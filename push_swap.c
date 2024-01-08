/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:04 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/08 16:10:57 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	push_swap(char **argv)
{
	stack	*stack_a;
	stack	*stack_b;
	//check if args is only digits and no empty args

	if (!check_digits(argv) || !check_empty(argv))
		return ;

	//stock arguments int a linked list

	stack_a = stock_args(argv);
	stack_b = 0;

	//check if args are valid, if some args arent integers or
	//there is a duplication, return NULL and prints "error\n"

	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	reverse_rotate_stack(&stack_a, &stack_b);
	if (!check_duplicate(stack_a))
		return ;
	while (stack_a)
	{
		ft_printf("stack_a :%i\n", stack_a->n);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		ft_printf("stack_b :%i\n", stack_b->n);
		stack_b = stack_b->next;
	}
	//sort integers by ascending order in stacks a and prints each step of the sorting like this "step\n"
	
	//sort_args(stack_a);
}