/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:43 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/02/06 18:02:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "libft/libft.h"
# include "limits.h"

typedef struct stack_list
{
	int					n;
	int					cost;
	struct stack_list	*next;
}	t_stack;

void	push_swap(char **argv);
t_stack	*stock_args(char **argv);
int		check_empty(char **argv);
int		check_digits(char **argv);
int		check_duplicate(t_stack *stack_a);
void	stack_addback(t_stack **stack_n, t_stack *new_node);
t_stack	*new_node(int n, int cost);
void	swap(t_stack **stack_n, char c);
void	swap_stack(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack **stack_in, t_stack **stack_out, char c);
void	stack_addfront(t_stack **stack_n, t_stack *new_node);
void	rotate(t_stack **stack_n, char c);
void	reverse_rotate(t_stack **stack_n, char c);
void	rotate_stack(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b);
t_stack	*last_node(t_stack *stack_n);
void	sort_three(t_stack **stack_a);
t_stack	*max_node(t_stack *stack_n);
t_stack	*min_node(t_stack *stack_n);
int		is_sort(t_stack *stack_a);
int		stack_len(t_stack *stack_n);
void	sort_algo(t_stack **stack_a);
void	set_cost(t_stack **s_a, t_stack **s_b);
t_stack	*get_cheapest(t_stack **stack_a, t_stack **stack_b);
void	for_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *node);
t_stack	*get_b_target(t_stack *p, t_stack **stack_b);
t_stack	*get_a_target(t_stack *p, t_stack **stack_a);
int		get_pose(t_stack **stack_n, int n);
void	free_stack(t_stack **stack_n);
void	for_rotate(t_stack **s_a, t_stack **s_b, int p_node, int p_target);
void	for_rrotate(t_stack **s_a, t_stack **s_b, int p_node, int p_target);
void	for_push_r(t_stack **stack_n, int pose, char c);
int		is_int(char *str);

#endif