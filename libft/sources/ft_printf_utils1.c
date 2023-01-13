/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:42:36 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/01 16:48:30 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parse_format(char c, va_list ap, int *len)
{
	if (c == 'c')
		ft_print_char(va_arg(ap, int), len);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (c == 'p')
		ft_print_ptr(va_arg(ap, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (c == 'u')
		ft_print_u(va_arg(ap, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(ap, unsigned int), len, c);
	else if (c == '%')
		ft_print_char('%', len);
}

void	ft_parse_bonus(char c, va_list ap, char d, int *len)
{
	if (c == '#')
		ft_print_0x(ap, d, len);
	else if (c == '+' || c == ' ' || c == '1')
		ft_print_positive(ap, c, d, len);
}
