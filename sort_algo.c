/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:37 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:41 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_twice(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b, 'b');
	if (stack_len(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = get_cheapest(stack_a, stack_b);
	for_push_b(stack_a, stack_b, tmp);
	push(stack_a, stack_b, 'b');
}

void	push_back_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*target;
	int		n;
	int		pose;
	int		len;

	tmp = *stack_b;
	target = get_a_target(tmp, stack_a);
	n = target->n;
	pose = get_pose(stack_a, n);
	len = stack_len(*stack_a);
	while ((*stack_a)->n != n)
	{
		if (pose <= len / 2)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	push(stack_b, stack_a, 'a');
}

void	min_top(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*min;
	int		pose;
	int		len;

	min = min_node(*stack_a);
	tmp = malloc(sizeof(t_stack));
	tmp->n = min->n;
	pose = get_pose(stack_a, min->n);
	len = stack_len(*stack_a);
	while (tmp->n != (*stack_a)->n)
	{
		if (pose <= len / 2)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	free(tmp);
}

void	sort_algo(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = 0;
	push_twice(stack_a, &stack_b);
	while (stack_len(*stack_a) != 3)
		push_b(stack_a, &stack_b);
	sort_three(stack_a);
	while (stack_len(stack_b) != 0)
		push_back_a(stack_a, &stack_b);
	min_top(stack_a);
}
