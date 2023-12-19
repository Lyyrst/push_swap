/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:05 by kbutor-b          #+#    #+#             */
/*   Updated: 2023/11/26 17:05:59 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		check_str(const char *str, va_list params, int n);
void	print_str(char c, va_list params, int *n);
void	ft_putstr(char *str, int *n);
void	ft_putchar(char c, int *n);
void	ft_putnbr_base(long long int n, char *base, int *nb);
void	ft_putupper_base(long long int n, char *base, int *nb);
void	check_unsigned(unsigned int n, int *nb);
int		ft_strlen(char *str);
void	print_p(unsigned long int n, int *nb);

#endif