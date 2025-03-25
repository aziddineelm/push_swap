/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:45:23 by ael-mans          #+#    #+#             */
/*   Updated: 2025/03/23 11:45:24 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack;
	int				size;
	int				chunk_size;
	int				min_index;
	int				max_index;
	int				*array;
}					t_data;

int			sa(t_stack **stack_a);
int			pa(t_stack **stack_a, t_stack **stack_b);
int			ra(t_stack **stack_a);
int			rra(t_stack **stack_a);
int			sb(t_stack **stack_b);
int			pb(t_stack **stack_a, t_stack **stack_b);
int			rb(t_stack **stack_b);
int			rrb(t_stack **stack_b);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			rrr(t_stack **stack_a, t_stack **stack_b);
int			is_sorted(t_stack *stack);
int			is_valid_integer(char **args);
int			has_duplicates(t_data *data);
int			validate_input(t_data *data, char **args);
char		*ft_strdup(const char *s);
int			ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
t_data		*init_stack_data(void);
int			free_stack_data(t_data *data);
void		ft_lstadd_front(t_stack **lst, t_stack *newer);
void		ft_lstadd_back(t_stack **lst, t_stack *newer);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);
int			get_value_index(t_stack *stack, int value);
t_stack		*get_stack_last(t_stack *stack);
void		create_sorted_array(t_stack *stack, t_data **data);
int			is_in_chunk(int value, int *array, int min, int max);
int			get_max_value(t_stack *stack);
int			get_min_value(t_stack *stack);
void		sort_stack(t_data *a, t_data *b);
void		sort_three_elements(t_stack **a);
void		sort_four_elements(t_stack **a, t_stack **b, t_data *data);
void		sort_five_elements(t_stack **a, t_stack **b, t_data *data);
void		sort_large_stack(t_stack **a, t_stack **b, t_data *data);
void		push_max_to_a(t_stack **a, t_stack **b);
int			determine_chunk_size(t_data *data);
int			free_args(char **args);
void		clean_exit(t_data *a, t_data *b, char **args);
void		exit_error(t_data *a, t_data *b, char **args);

#endif
