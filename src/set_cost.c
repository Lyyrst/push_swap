/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:35 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:22:41 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pose(t_stack **stack_n, int n)
{
	int		pose;
	t_stack	*p;

	p = *stack_n;
	pose = 1;
	while (p->n != n)
	{
		pose++;
		p = p->next;
	}
	return (pose);
}

int	cost(t_stack *p, t_stack **stack_n)
{
	t_stack	*tmp;
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

t_stack	*get_b_target(t_stack *p, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*ret;
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

t_stack	*get_a_target(t_stack *p, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*ret;
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

void	set_cost(t_stack **s_a, t_stack **s_b)
{
	t_stack	*p;

	p = *s_a;
	while (p)
	{
		p->cost = cost(p, s_a) + cost(get_b_target(p, s_b), s_b) + 1;
		p = p->next;
	}
}
