/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:22:02 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 16:17:02 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_overflow(long value, int sign)
{
	if (sign > 0 && value > INT_MAX)
		return (1);
	if (sign < 0 && (-value) < INT_MIN)
		return (1);
	return (0);
}

int	has_integer_overflow(char **args)
{
	int		i;
	int		j;
	long	value;
	int		sign;

	i = -1;
	while (args[++i])
	{
		j = 0;
		sign = 1;
		value = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			if (args[i][j++] == '-')
				sign = -1;
		}
		while (args[i][j] >= '0' && args[i][j] <= '9')
		{
			if (check_overflow(value * 10 + (args[i][j] - '0'), sign))
				return (1);
			value = value * 10 + (args[i][j] - '0');
			j++;
		}
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
