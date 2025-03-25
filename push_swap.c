/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:27:53 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:53:14 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_partial_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	parse_args_to_stack(char **args, t_data **data)
{
	t_stack	*current;
	int		i;

	i = 1;
	(*data)->stack = malloc(sizeof(t_stack));
	if (!(*data)->stack)
		return (0);
	(*data)->stack->value = ft_atoi(args[0]);
	(*data)->stack->next = NULL;
	current = (*data)->stack;
	while (args[i])
	{
		current->next = malloc(sizeof(t_stack));
		if (!current->next)
			return (free_args(args), free_partial_stack((*data)->stack), 0);
		current = current->next;
		current->value = ft_atoi(args[i]);
		current->next = NULL;
		i++;
	}
	(*data)->size = count_args(args);
	create_sorted_array((*data)->stack, data);
	return (1);
}

char	**parse_input_args(char **argv)
{
	int		i;
	char	*tmp;
	char	*str;
	char	**args;

	i = 0;
	if (!argv[i] || !argv[i][0])
		return (NULL);
	str = ft_strdup(argv[i]);
	if (!str)
		return (NULL);
	i++;
	while (argv[i])
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		if (!tmp || !argv[i][0])
			return (free(tmp), NULL);
		str = tmp;
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;
	char	**args;

	if (argc < 2)
		return (0);
	a = init_stack_data();
	b = init_stack_data();
	if (!a || !b)
		return (0);
	args = parse_input_args(argv + 1);
	if (args == NULL)
		exit_error(a, b, args);
	if (!parse_args_to_stack(args, &a))
		exit_error(a, b, args);
	if (!validate_input(a, args) || !is_valid_integer(args))
		exit_error(a, b, args);
	sort_stack(a, b);
	clean_exit(a, b, args);
	return (0);
}
