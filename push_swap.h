/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:04:58 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/01/03 18:29:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdlib.h"
#include "libft/libft.h"
#include "limits.h"

void	push_swap(int argc, char **argv);
t_list	*stock_args(int argc, char **argv);
int	check_empty(char **argv);
int	check_digits(char **argv);
int	check_duplicate(t_list *stack_a);

# endif