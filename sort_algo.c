/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:37 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/17 19:19:07 by kbutor-b         ###   ########.fr       */
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
	stack	*target;
	int		pose;
	int		pose_b;
	int		len;

	tmp = get_cheapest(stack_a, stack_b);
	target = get_b_target(tmp, stack_b);
	//ft_printf("cheapest : %d  |  cost : %d  |  ", tmp->n, tmp->cost);
	pose = get_pose(stack_a, tmp);
	pose_b = get_pose(stack_b, target);
	len = stack_len(*stack_a);
	//ft_printf("b target : %d  |  pose : %d\n", target->n, pose_b);
	for_push(stack_b, target->n, pose_b, 'b');
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
	stack	*target;

	tmp = *stack_b;
	target = get_a_target(tmp, stack_a);
	//ft_printf("node : %d  |  target : %d\n", tmp->n, target->n);
	for_push(stack_a, target->n, get_pose(stack_a, target),'a');
	push(stack_b, stack_a, 'a');
}

void	min_top(stack **stack_a)
{
	stack	*tmp;
	stack	*min;
	int		pose;
	int		len;

	min = min_node(*stack_a);
	tmp = malloc(sizeof(stack));
	tmp->n = min->n;
	pose = get_pose(stack_a, min);
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
	/*ft_printf("*----*----*\n");
	while (stack_b)
	{
		ft_printf("b : %d\n", stack_b->n);
		stack_b = stack_b->next;
	}*/
}