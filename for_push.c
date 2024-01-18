/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:43:17 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:59:13 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_rotate(t_stack **s_a, t_stack **s_b, int p_node, int p_target)
{
	if (p_node != 1 && p_target != 1)
		rotate_stack(s_a, s_b);
	else if (p_node > 1)
		rotate(s_a, 'a');
	else if (p_target > 1)
		rotate(s_b, 'b');
}

void	for_rrotate(t_stack **s_a, t_stack **s_b, int p_node, int p_target)
{
	if (p_node != 1 && p_target != 1)
		reverse_rotate_stack(s_a, s_b);
	else if (p_node > 1)
		reverse_rotate(s_a, 'a');
	else if (p_target > 1)
		reverse_rotate(s_b, 'b');
}

void	for_push_r(t_stack **stack_n, int pose, char c)
{
	if (pose <= stack_len(*stack_n) / 2)
		rotate(stack_n, c);
	else
		reverse_rotate(stack_n, c);
}
