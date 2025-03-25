/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:40:39 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 15:54:57 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	execute_operation(char *line, t_data *a, t_data *b)
{
	if (!ft_strncmp("sa", line, 2) && (line[2] == '\n'))
		sa(&a->stack);
	else if (!ft_strncmp("sb", line, 2) && (line[2] == '\n'))
		sb(&b->stack);
	else if (!ft_strncmp("pb", line, 2) && (line[2] == '\n'))
		pb(&a->stack, &b->stack);
	else if (!ft_strncmp("pa", line, 2) && (line[2] == '\n'))
		pa(&a->stack, &b->stack);
	else if (!ft_strncmp("ra", line, 2) && (line[2] == '\n'))
		ra(&a->stack);
	else if (!ft_strncmp("rb", line, 2) && (line[2] == '\n'))
		rb(&b->stack);
	else if (!ft_strncmp("rra", line, 3) && (line[3] == '\n'))
		rra(&a->stack);
	else if (!ft_strncmp("rrb", line, 3) && (line[3] == '\n'))
		rrb(&b->stack);
	else if (!ft_strncmp("ss", line, 2) && (line[2] == '\n'))
		ss(&a->stack, &b->stack);
	else if (!ft_strncmp("rr", line, 2) && (line[2] == '\n'))
		rr(&a->stack, &b->stack);
	else if (!ft_strncmp("rrr", line, 3) && (line[3] == '\n'))
		rrr(&a->stack, &b->stack);
	else
		return (-1);
	return (0);
}

int	execute_and_check(t_data *a, t_data *b)
{
	char	*line;
	int		error_flag;

	error_flag = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (execute_operation(line, a, b) == -1)
		{
			error_flag = 1;
			free(line);
			break ;
		}
		free(line);
	}
	return (error_flag);
}

int	run_checker(t_data *a, t_data *b, char **args)
{
	int	error_flag;

	error_flag = execute_and_check(a, b);
	if (error_flag)
	{
		write(2, "Error\n", 6);
		clean_exit(a, b, args);
		exit(1);
	}
	if (is_sorted(a->stack) && !b->stack)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_exit(a, b, args);
	exit(0);
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
	run_checker(a, b, args);
	return (0);
}
