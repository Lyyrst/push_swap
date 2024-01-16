/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:35 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/11 20:15:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pose(stack **stack_n, stack *target)
{
	int		pose;
	stack	*p;

	p = *stack_n;
	pose = 0;
	while (p != target)
	{
		pose++;
		p = p->next;
	}
	return (pose);
}

int	cost(stack *p, stack **stack_n)
{
	stack	*tmp;
	int		len;
	int		pose;

	tmp = *stack_n;
	len = stack_len(tmp);
	pose = 1;
	while (p != tmp && tmp)
	{
		pose++;
		tmp = tmp->next;
	}
	if (pose > len / 2)
		return (len - pose + 1);
	return (pose - 1);
}

stack	*get_b_target(stack *p, stack **stack_b)
{
	stack	*tmp;
	stack	*ret;
	int		n;

	tmp = *stack_b;
	ret = 0;
	n = INT_MIN;
	while (tmp)
	{
		if (p->n > tmp->n && n < tmp->n)
		{
			ret = tmp;
			n = tmp->n;
		}
		tmp = tmp->next;
	}
	if (ret == 0)
		ret = max_node(*stack_b);
	return (ret);
}

stack	*get_a_target(stack *p, stack **stack_a)
{
	stack	*tmp;
	stack	*ret;
	int		n;

	tmp = *stack_a;
	ret = 0;
	n = INT_MAX;
	while (tmp)
	{
		if (p->n < tmp->n && n > tmp->n)
		{
			ret = tmp;
			n = tmp->n;
		}
		tmp = tmp->next;
	}
	if (ret == 0)
		ret = min_node(*stack_a);
	return (ret);
}

void	set_cost(stack **stack_a, stack **stack_b)
{
	stack	*p;

	p = *stack_a;
	while(p)
	{
		p->cost = cost(p, stack_a) + cost(get_b_target(p, stack_b), stack_b);
		p = p->next;
	}
}