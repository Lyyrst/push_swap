/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:16 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/26 17:10:59 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long int n, char *base, int *nb)
{
	unsigned long int	blen;

	blen = (unsigned long int)ft_strlen(base);
	if (n >= blen)
	{
		ft_putnbr_base(n / blen, base, nb);
		ft_putnbr_base(n % blen, base, nb);
	}
	else
		ft_putchar(base[n], nb);
}

void	print_p(unsigned long int n, int *nb)
{
	if (!n)
	{
		ft_putstr("(nil)", nb);
		return ;
	}
	ft_putstr("0x", nb);
	ft_put_pointer(n, "0123456789abcdef", nb);
}
