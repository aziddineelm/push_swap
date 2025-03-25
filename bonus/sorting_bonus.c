/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:04:05 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 21:41:16 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_stack(t_data *a, t_data *b)
{
	if (a->size == 2)
		sa(&a->stack);
	else if (a->size == 3)
		sort_three_elements(&a->stack);
	else if (a->size == 4)
		sort_four_elements(&a->stack, &b->stack, a);
	else if (a->size == 5)
		sort_five_elements(&a->stack, &b->stack, a);
	else
		sort_large_stack(&a->stack, &b->stack, a);
}

void	handle_three_element_cases(t_stack **a, int index, t_stack *last)
{
	if (index == 1)
	{
		if ((*a)->value > last->value)
			ra(a);
		else
			sa(a);
	}
	else if (index == 2)
	{
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
			rra(a);
		}
		else
			rra(a);
	}
}

void	sort_three_elements(t_stack **a)
{
	int		index;
	t_stack	*last;

	if (is_sorted(*a))
		return ;
	last = ft_lstlast(*a);
	index = get_value_index(*a, get_min_value(*a));
	if (index == 0)
	{
		sa(a);
		ra(a);
	}
	else
		handle_three_element_cases(a, index, last);
}

void	sort_four_elements(t_stack **a, t_stack **b, t_data *data)
{
	int	index;

	if (is_sorted(*a))
		return ;
	data->size = ft_lstsize(*a);
	index = get_value_index(*a, get_min_value(*a));
	if (index <= data->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < data->size)
			rra(a);
	pb(a, b);
	sort_three_elements(a);
	pa(a, b);
}

void	sort_five_elements(t_stack **a, t_stack **b, t_data *data)
{
	int	index;

	data->size = ft_lstsize(*a);
	index = get_value_index(*a, get_min_value(*a));
	if (index <= data->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < data->size)
			rra(a);
	pb(a, b);
	sort_four_elements(a, b, data);
	pa(a, b);
}
