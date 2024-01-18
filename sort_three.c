/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:43 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:23:50 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*big;

	big = max_node(*stack_a);
	if (big == *stack_a)
		rotate(stack_a, 'a');
	else if (big == (*stack_a)->next)
		reverse_rotate(stack_a, 'a');
	if ((*stack_a)->n > (*stack_a)->next->n)
		swap(stack_a, 'a');
}
