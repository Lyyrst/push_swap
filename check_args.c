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
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
			j++;
		if (ft_strlen(argv[i]) == j || ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
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
			else if ((is_sign(argv[i][j]) == 1 && ft_isdigit(argv[i][j + 1]) == 1 && ft_isdigit(argv[i][j - 1]) == 0) || ft_isdigit(argv[i][j]) == 1)
				j++;
			else
			{
				ft_putstr_fd("Error\n", 2);
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

	while (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			if (tmp->next->n == stack_a->n)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}