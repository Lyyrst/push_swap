/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:36 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/18 15:16:28 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (n >= INT_MIN && n <= INT_MAX)
		return (1);
	return (0);
}

int	fill_stack(t_stack **stack_a, char *str)
{
	int	i;

	if (!is_int(str))
	{
		ft_printf("Error : an argument is bigger than an int\n");
		return (0);
	}
	i = ft_atoi(str);
	if (!*stack_a)
		*stack_a = new_node(i, 0);
	else
		stack_addback(stack_a, new_node(i, 0));
	return (1);
}

t_stack	*stock_args(char **argv)
{
	t_stack	*stack_a;
	char	**array;
	int		i;
	int		j;

	i = 1;
	stack_a = 0;
	while (argv[i])
	{
		array = ft_split(argv[i], ' ');
		if (!array)
			return (0);
		j = 0;
		while (array[j])
		{
			if (!fill_stack(&stack_a, array[j]))
				return (0);
			j++;
		}
		i++;
		ft_freesplit(array, 0);
	}
	return (stack_a);
}
