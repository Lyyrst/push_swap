/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:37 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/11 20:08:33 by marvin           ###   ########.fr       */
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
	pose = get_pose(stack_a, tmp);
	len = stack_len(*stack_a);
	for_push(stack_b, get_b_target(tmp, stack_b), pose, 'b');
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

void	push_back_a(stack **stack_a, stack **stack_b)
{
	stack	*tmp;
	stack	*p;

	tmp = *stack_b;
	p = get_a_target(tmp, stack_a);
	for_push(stack_a, p, 0, 'a');
	push(stack_b, stack_a, 'a');
}

void	min_top(stack **stack_a)
{
	stack	*tmp;
	int		pose;
	int		len;

	tmp = min_node(*stack_a);
	pose = get_pose(stack_a, tmp);
	len = stack_len(*stack_a);
	while (tmp->n != (*stack_a)->n)
	{
		if (pose <= len / 2)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}

void	sort_algo(stack **stack_a)
{
	stack	*stack_b;

	stack_b = 0;
	push_twice(stack_a, &stack_b);
	while (stack_len(*stack_a) != 3)
		push_b(stack_a, &stack_b);
	sort_three(stack_a);
	while (stack_len(stack_b) != 0)
		push_back_a(stack_a, &stack_b);
	min_top(stack_a);
	ft_printf("*----*----*\n");
	while (stack_b)
	{
		ft_printf("b : %d\n", stack_b->n);
		stack_b = stack_b->next;
	}
}