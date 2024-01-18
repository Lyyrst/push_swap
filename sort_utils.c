/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:06:41 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 16:00:57 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack *stack_n)
{
	t_stack	*ret;
	int		max_value;

	max_value = INT_MIN;
	ret = stack_n;
	while (stack_n)
	{
		if (stack_n->n > max_value)
		{
			max_value = stack_n->n;
			ret = stack_n;
		}
		stack_n = stack_n->next;
	}
	return (ret);
}

t_stack	*min_node(t_stack *stack_n)
{
	t_stack	*ret;
	int		min_value;

	min_value = INT_MAX;
	ret = stack_n;
	while (stack_n)
	{
		if (stack_n->n < min_value)
		{
			min_value = stack_n->n;
			ret = stack_n;
		}
		stack_n = stack_n->next;
	}
	return (ret);
}

int	is_sort(t_stack *stack_a)
{
	int	n;

	n = 1;
	while (stack_a->next)
	{
		if (!(stack_a->n < stack_a->next->n))
		{
			n = 0;
			break ;
		}
		stack_a = stack_a->next;
	}
	return (n);
}

t_stack	*get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	t_stack	*ret;

	p = *stack_a;
	ret = *stack_a;
	set_cost(stack_a, stack_b);
	while (p)
	{
		if (ret->cost > p->cost)
			ret = p;
		p = p->next;
	}
	return (ret);
}

void	for_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int		pn;
	int		pt;
	int		n_node;
	int		n_target;

	n_node = node->n;
	n_target = (get_b_target(node, stack_b))->n;
	pn = get_pose(stack_a, n_node);
	pt = get_pose(stack_b, n_target);
	while (pn != 1 || pt != 1)
	{
		if (pn <= stack_len(*stack_a) / 2 && pt <= stack_len(*stack_b) / 2)
			for_rotate(stack_a, stack_b, pn, pt);
		else if (pn > stack_len(*stack_a) / 2 && pt > stack_len(*stack_b) / 2)
			for_rrotate(stack_a, stack_b, pn, pt);
		else
		{
			if (pn != 1)
				for_push_r(stack_a, pn, 'a');
			if (pt != 1)
				for_push_r(stack_b, pt, 'b');
		}
		pn = get_pose(stack_a, n_node);
		pt = get_pose(stack_b, n_target);
	}
}
