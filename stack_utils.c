/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:44:06 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/08 15:39:33 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*new_node(int n, int cost)
{
	stack	*node;

	node = malloc(sizeof(stack));
	if (!node)
		return (0);
	node->n = n;
	node->cost = cost;
	node->next = 0;
	return (node);
}

void	stack_addback(stack **stack_n, stack *new_node)
{
	stack	*p;

	p = *stack_n;
	if (!stack_n || !new_node)
		return ;
	if (*stack_n == 0)
	{
		*stack_n = new_node;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = new_node;
}

void	stack_addfront(stack **stack_n, stack *new_node)
{
	new_node->next = *stack_n;
	*stack_n = new_node;
}

stack	*last_node(stack *stack_n)
{
	if (!stack_n)
		return (0);
	while (stack_n->next)
		stack_n = stack_n->next;
	return (stack_n);
}