/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:37 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/10 19:32:44 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_twice(stack **stack_a, stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	if (stack_len(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
}

void	push_b(stack **stack_a, stack **stack_b)
{
	stack	*tmp;
	stack	*p;
	int		pose;
	int		len;

	tmp = get_cheapest(stack_a, stack_b);
	p = *stack_a;
	pose = 0;
	len = stack_len(*stack_a);
	while (p != tmp)
	{
		pose++;
		p = p->next;
	}
	for_push_b(stack_b, get_b_target(tmp, stack_b), pose);
	if (pose <= len / 2)
	{
		while ((*stack_a)->n != tmp->n)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->n != tmp->n)
			reverse_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
}

void	sort_algo(stack **stack_a)
{
	stack	*stack_b;

	stack_b = 0;
	push_twice(stack_a, &stack_b);
	while (stack_len(*stack_a) != 3)
		push_b(stack_a, &stack_b);
	sort_three(stack_a);
	ft_printf("*----*----*\n");
	while (stack_b)
	{
		ft_printf("b : %d\n", stack_b->n);
		stack_b = stack_b->next;
	}
}