/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:36 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/04 18:23:38 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_int(char *str)
{
	long	n;

	n = ft_atoi(str);
	if (!(n <= INT_MAX && n >= INT_MIN))
		return (0);
	return (1);
}

int	fill_stack(t_list **stack_a, char *str)
{
	void	*n;
	int 	i;

	if (!is_int(str))
	{
		ft_printf("Error : an argument is bigger than an int\n");
		return (0);
	}
	i = (int)ft_atoi(str);
	//n = &i;
	if (!*stack_a)
		*stack_a = ft_lstnew(n);
	else
		ft_lstadd_back(stack_a, ft_lstnew(n));
	return (1);
}

t_list	*stock_args(char **argv)
{
	t_list	*stack_a;
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
