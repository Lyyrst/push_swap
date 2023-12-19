/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:12 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/12/19 18:55:11 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

stack	*new_node(int	n)
{
	stack	*node;

	node = malloc(sizeof(stack));
	if (!node)
		return (0);
	node->i = n;
	node->next = 0;
	return (node);
}

void	add_node(stack **stack_a, stack *new)
{
	new->next = *stack_a;
	*stack_a = new;
}

stack	*stock_args(int argc, char **argv)
{
	stack	*stack_a;
	int		n;

	argc--;
	n = ft_atoi(argv[argc]);
	stack_a = new_node(n);
	while (argc-- > 1)
	{
		n = ft_atoi(argv[argc]);
		add_node(&stack_a, new_node(n));
	}
	return (stack_a);
}