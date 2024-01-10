/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:43 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/10 19:32:37 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdlib.h"
#include "libft/libft.h"
#include "limits.h"

typedef struct stack_list
{
	int					n;
	int					cost;
	struct stack_list	*next;
}	stack;

void	push_swap(char **argv);
stack	*stock_args(char **argv);
int		check_empty(char **argv);
int		check_digits(char **argv);
int		check_duplicate(stack *stack_a);
void	stack_addback(stack **stack_n, stack *new_node);
stack	*new_node(int n, int cost);
void 	swap(stack **stack_n, char c);
void	swap_stack(stack *stack_a, stack *stack_b);
void	push(stack **stack_in, stack **stack_out, char c);
void	stack_addfront(stack **stack_n, stack *new_node);
void	rotate(stack **stack_n, char c);
void	reverse_rotate(stack **stack_n, char c);
void	rotate_stack(stack **stack_a, stack **stack_b);
void	reverse_rotate_stack(stack **stack_a, stack **stack_b);
stack	*last_node(stack *stack_n);
void	sort_three(stack **stack_a);
stack	*max_node(stack* stack_n);
stack	*min_node(stack* stack_n);
int		is_sort(stack *stack_a);
int		stack_len(stack *stack_n);
void	sort_algo(stack **stack_a);
void	set_cost(stack **stack_a, stack **stack_b);
stack	*get_cheapest(stack **stack_a, stack **stack_b);
void	for_push_b(stack **stack_b, stack *target, int pose);
stack	*get_b_target(stack *p, stack **stack_b);

# endif