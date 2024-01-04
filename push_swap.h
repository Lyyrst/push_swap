/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:26:43 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/04 17:24:32 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdlib.h"
#include "libft/libft.h"
#include "limits.h"

void	push_swap(char **argv);
t_list	*stock_args(char **argv);
int	check_empty(char **argv);
int	check_digits(char **argv);
int	check_duplicate(t_list *stack_a);

# endif