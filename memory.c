/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:18:37 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:20:27 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_data *a, t_data *b, char **args)
{
	write(2, "Error\n", 6);
	clean_exit(a, b, args);
	exit(0);
}

int	free_args(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

void	clean_exit(t_data *a, t_data *b, char **args)
{
	if (args)
		free_args(args);
	if (a)
		free_stack_data(a);
	if (b)
		free_stack_data(b);
}
