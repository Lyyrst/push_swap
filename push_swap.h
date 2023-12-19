/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:04:58 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/12/19 19:08:39 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdlib.h"

typedef struct list_stack
{
	int					i;
	struct list_stack	*next;
}	stack;

void	push_swap(int argc, char **argv);
stack	*stock_args(int argc, char **argv);

# endif