/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:18:04 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 21:38:26 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	index;
	int	size;

	size = ft_lstsize(*b);
	index = get_value_index(*b, get_max_value(*b));
	if (index <= size / 2)
		while ((*b)->value != get_max_value(*b))
			rb(b);
	else
		while ((*b)->value != get_max_value(*b))
			rrb(b);
	pa(a, b);
}

int	determine_chunk_size(t_data *data)
{
	int	chunk_size;

	if (data->size <= 16)
		chunk_size = 5;
	else if (data->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 40;
	return (chunk_size);
}

void	sort_large_stack(t_stack **a, t_stack **b, t_data *data)
{
	data->chunk_size = determine_chunk_size(data);
	data->size = ft_lstsize(*a);
	while (*a)
	{
		if (is_in_chunk((*a)->value, data->array, data->min_index,
				data->chunk_size))
		{
			pb(a, b);
			if (data->chunk_size < data->size)
				data->chunk_size++;
			data->min_index++;
		}
		else if ((*a)->value < data->array[data->min_index])
		{
			pb(a, b);
			rb(b);
			if (data->chunk_size < data->size)
				data->chunk_size++;
			data->min_index++;
		}
		else
			ra(a);
	}
	while (*b)
		push_max_to_a(a, b);
}
