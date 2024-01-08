/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:54 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/04 16:26:54 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_printf("Error : argument %d is empty\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			else if ((is_sign(argv[i][j]) == 1 && ft_isdigit(argv[i][j + 1]) == 1) || ft_isdigit(argv[i][j]) == 1)
				j++;
			else
			{
				ft_printf("Error : one of the argument is not an integer\n", i);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_duplicate(stack *stack_a)
{
	stack	*tmp;
	int		n;

	n = 1;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			if (tmp->next->n == stack_a->n)
			{
				ft_printf("Error : argument %d has a duplicate\n", n);
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
		n++;
	}
	return (1);
}