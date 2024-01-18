/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:18:19 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:15:50 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack_n)
{
	t_stack	*tmp;

	if (!*stack_n || !stack_n)
		return ;
	while (*stack_n)
	{
		tmp = *stack_n;
		*stack_n = tmp->next;
		free(tmp);
	}
	*stack_n = 0;
}
