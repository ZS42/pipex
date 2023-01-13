/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:59:50 by zsyyida           #+#    #+#             */
/*   Updated: 2022/08/30 03:26:15 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(unsigned int n, int *len, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_print_hex (n / 16, len, c);
	ft_print_char (hex[n % 16], len);
}

void	ft_print_ptr(unsigned long long n, int *len)
{
	ft_print_char('0', len);
	ft_print_char('x', len);
	ft_print_ptrhex(n, len);
}

void	ft_print_ptrhex(unsigned long long n, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_print_ptrhex(n / 16, len);
	ft_print_char(hex[n % 16], len);
}
