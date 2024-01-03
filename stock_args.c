/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:12 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 19:23:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	is_int(char *str)
{

}*/

int	fill_stack(t_list *stack_a, char *str)
{
	void	*n;
	int 	i;

	/*if (!is_int)
	{
		ft_printf("Error : an argument is bigger than an int\n");
		return (0);
	}*/
	i = ft_atoi(str);
	n = &i;
	if (!stack_a)
		stack_a = ft_lstnew(n);
	else
		ft_lstadd_back(&stack_a, ft_lstnew(n));
}

t_list	*stock_args(int argc, char **argv)
{
	t_list	*stack_a;
	char	**array;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		array = ft_split(array[i], ' ');
		if (!array)
			return (0);
		j = 0;
		while (array[j])
		{
			if (!fill_stack(stack_a, array[j]))
				return (0);
			j++;
		}
		i++;
		ft_freesplit(array, 0);
	}
	return (stack_a);
}
