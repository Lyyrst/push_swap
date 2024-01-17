/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:04 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/17 16:21:18 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(stack **stack_a, int len)
{
	if (!stack_a || len < 2)
		return ;
	if (len == 2)
		swap(stack_a, 'a');
	if (len == 3)
		sort_three(stack_a);
	if (len > 3)
		sort_algo(stack_a);
}

void	push_swap(char **argv)
{
	stack	*stack_a;
	int		len;

	if (!check_digits(argv) || !check_empty(argv))
		return ;
	stack_a = stock_args(argv);
	len = stack_len(stack_a);
	if (!check_duplicate(stack_a))
		return ;
	if (is_sort(stack_a))
		return ;
	sort_stack(&stack_a, len);
	/*ft_printf("*----*----*\n");
	while (stack_a)
	{
		ft_printf("a : %d\n", stack_a->n);
		stack_a = stack_a->next;
	}
	ft_printf("*----*----*\n");*/
	free_stack(&stack_a);
}