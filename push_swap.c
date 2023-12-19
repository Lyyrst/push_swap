/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:38 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/12/19 19:08:44 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

int	check_stack(stack *stack_a)
{
	stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			if (tmp->next->i == stack_a->i)
			{
				ft_printf("Error\n");
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	stack	*stack_a;
	//stock arguments int a linked list

	stack_a = stock_args(argc, argv);

	//check if args are valid, if some args arent integers or
	//there is a duplication, return NULL and prints "error\n"

	if (!check_stack(stack_a))
		return ;
	while (stack_a)
	{
		ft_printf("%i\n",stack_a->i);
		stack_a = stack_a->next;
	}
	//sort integers by ascending order in stacks a and prints each step of the sorting like this "step\n"
	
	//sort_args(stack_a);
}