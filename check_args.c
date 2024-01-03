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
			if (argv[i][j] && (argv[i][j] == ' ' || ft_isdigit(argv[i][j]) == 1))
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

int	check_duplicate(t_list *stack_a)
{
	t_list	*tmp;
	int		n;

	n = 1;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			if (tmp->next->content == stack_a->content)
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