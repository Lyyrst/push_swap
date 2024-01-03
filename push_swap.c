/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:38 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 17:01:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	//check if args is only digits and no empty args

	if (!check_digits(argv) || !check_empty(argv))
		return ;

	//stock arguments int a linked list

	stack_a = stock_args(argc, argv);

	//check if args are valid, if some args arent integers or
	//there is a duplication, return NULL and prints "error\n"

	if (!check_duplicate(stack_a))
		return ;
	while (stack_a)
	{
		ft_printf("%i\n",stack_a->content);
		stack_a = stack_a->next;
	}
	//sort integers by ascending order in stacks a and prints each step of the sorting like this "step\n"
	
	//sort_args(stack_a);
}