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
			return (0);
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

	if (!argv[0] || !argv[0][0])
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	i = 0;
	str = ft_strdup(argv[i]);
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

	if (argc < 3)
		return (0);
	if (!(a = init_stack_data()))
		return (0);
	args = parse_input_args(argv + 1);
	if (args == NULL)
	{
		write(2, "Error\n", 6);
		clean_exit(a, NULL, NULL);
		return (1);
	}
	parse_args_to_stack(args,  &a);
	if (!validate_input(a, args) || !is_valid_integer(args))
	{
		write(2, "Error\n", 6);
		clean_exit(a, NULL, args);
		exit(1);
	}
	if (!(b = init_stack_data()))
		return (0);
	sort_stack(a, b);
	clean_exit(a, b, args);
	return (0);
}
