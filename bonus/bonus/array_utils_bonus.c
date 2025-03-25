/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:19:45 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:19:55 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	bubble_sort_array(t_stack **stack, t_data **data)
{
	int	i;
	int	j;
	int	tmp;
	int	size;

	i = 0;
	size = ft_lstsize(*stack);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if ((*data)->array[j] > (*data)->array[j + 1])
			{
				tmp = (*data)->array[j];
				(*data)->array[j] = (*data)->array[j + 1];
				(*data)->array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	create_sorted_array(t_stack *stack, t_data **data)
{
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	size = ft_lstsize(stack);
	(*data)->array = malloc(size * sizeof(int));
	if (!(*data)->array)
		return ;
	while (tmp)
	{
		(*data)->array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort_array(&stack, data);
}

int	is_in_chunk(int value, int *array, int min, int max)
{
	int	i;

	i = min;
	while (i < max)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	get_max_value(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->value;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min_value(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack->next;
	min = stack->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
