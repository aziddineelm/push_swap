/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:22:02 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:17:04 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	has_integer_overflow(char **args)
{
	int		i;
	long	value;
	int		j;
	int		sign;

	i = 0;
	while (args[i])
	{
		j = 0;
		sign = 1;
		value = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			if (args[i][j] == '-')
				sign = -1;
			j++;
		}
		while (args[i][j] >= '0' && args[i][j] <= '9')
		{
			value = value * 10 + (args[i][j++] - '0');
			if ((sign == 1 && value > INT_MAX) || (sign == -1 &&
					-value < INT_MIN))
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	is_valid_integer(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (0);
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_duplicates(t_data *data)
{
	int	i;
	int	j;
	int	size;

	size = data->size;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data->array[i] == data->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(t_data *data, char **args)
{
	if (has_integer_overflow(args))
		return (0);
	if (has_duplicates(data))
		return (0);
	if (is_sorted(data->stack))
	{
		clean_exit(data, NULL, args);
		exit(0);
	}
	return (1);
}
