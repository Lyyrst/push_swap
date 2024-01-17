/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:06:41 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/17 18:53:29 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*max_node(stack* stack_n)
{
	stack	*ret;
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

stack	*min_node(stack* stack_n)
{
	stack	*ret;
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

int	is_sort(stack *stack_a)
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

stack	*get_cheapest(stack **stack_a, stack **stack_b)
{
	stack	*p;
	stack	*ret;

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

void	for_push(stack **stack_n, int n, int pose, char c)
{
	int	len;

	len = stack_len(*stack_n);
	while ((*stack_n)->n != n)
	{
		if (pose <= len / 2)
			rotate(stack_n, c);
		else
			reverse_rotate(stack_n, c);
	}
}