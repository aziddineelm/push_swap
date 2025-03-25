/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:19:02 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:19:13 by ael-mans         ###   ########.fr       */
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

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	tmp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*get_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_value_index(t_stack *stack, int value)
{
	int		index;
	t_stack	*tmp;

	tmp = stack;
	index = 0;
	while (tmp)
	{
		if (value == tmp->value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}
