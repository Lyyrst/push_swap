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
			else if ((is_sign(argv[i][j]) == 1
				&& ft_isdigit(argv[i][j + 1]) == 1
				&& ft_isdigit(argv[i][j - 1]) == 0)
				|| ft_isdigit(argv[i][j]) == 1)
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

int	check_duplicate(t_stack *stack_a)
{
	t_stack	*tmp;

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

long int	ft_atol(const char *str)
{
	int			i;
	long int	ret;
	int			par;

	i = 0;
	ret = 0;
	par = 0;
	if (str[0] == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32)
			i++;
	if (str[i] == '-')
		par = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9')
		&& str[i])
	{
		ret *= 10;
		ret += str[i++] - 48;
	}
	if (par == 1)
		return (ret * -1);
	return (ret);
}

int	is_int(char *str)
{
	long int	n;

	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}