/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:48:37 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 23:47:17 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	cmp(char *line, t_data *a, t_data *b, char **args)
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
		return (clean_exit(a, b, args), -1);
	return (0);
}

int	check(t_data *a, t_data *b, char **args)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		i = cmp(line, a, b, args);
		if (i == -1)
		{
			free(line);
			exit(1);
		}
		free(line);
	}
	if (is_sorted(a->stack) && !b->stack)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean_exit(a, b, args);
	exit(0);
}
