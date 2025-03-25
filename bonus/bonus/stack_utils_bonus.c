/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 09:50:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/25 21:41:21 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_data	*init_stack_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->stack = NULL;
	data->chunk_size = 0;
	data->array = 0;
	data->min_index = 0;
	data->max_index = 0;
	data->size = 0;
	return (data);
}

int	free_stack_data(t_data *data)
{
	t_stack	*current;
	t_stack	*next;

	if (!data)
		return (0);
	current = data->stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (data->array)
		free(data->array);
	free(data);
	return (0);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}
