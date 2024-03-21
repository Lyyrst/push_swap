/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:21:18 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:21:10 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_n, char c)
{
	t_stack	*p;
	int		n;
	int		cost;

	p = *stack_n;
	if (p->next == 0)
		return ;
	n = p->n;
	cost = p->cost;
	p->n = p->next->n;
	p->cost = p->next->cost;
	p->next->n = n;
	p->next->cost = cost;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf ("sb\n");
}

void	swap_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a, 0);
	swap(&stack_b, 0);
	ft_printf("ss\n");
}

void	push(t_stack **stack_in, t_stack **stack_out, char c)
{
	t_stack	*p_in;

	p_in = *stack_in;
	if (!*stack_in)
		return ;
	stack_addfront(stack_out, new_node(p_in->n, p_in->cost));
	*stack_in = (*stack_in)->next;
	free (p_in);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_stack **stack_n, char c)
{
	t_stack	*p;

	p = *stack_n;
	if (p->next == 0)
		return ;
	stack_addback(stack_n, new_node(p->n, p->cost));
	*stack_n = (*stack_n)->next;
	free(p);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rr\n");
}
