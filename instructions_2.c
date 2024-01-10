/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:30:14 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/10 16:18:09 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(stack **stack_n, char c)
{
	stack	*p;
	stack	*tmp;

	if ((*stack_n)->next == 0)
		return ;
	tmp = *stack_n;
	while (tmp->next->next)
		tmp = tmp->next;
	p = tmp->next;
	stack_addfront(stack_n, new_node(p->n, p->cost));
	free(p);
	tmp->next = 0;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_stack(stack **stack_a, stack **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	ft_printf("rrr\n");
}