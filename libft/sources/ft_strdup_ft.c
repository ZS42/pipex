/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:33:15 by zsyyida           #+#    #+#             */
/*   Updated: 2022/12/16 18:20:56 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_ft(const char *s1)
{
	char	*str;
	int		len;

	str = (char *)s1;
	len = ft_strlen_ft(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_memcpy_ft(str, s1, len);
	str[len] = '\0';
	return (str);
}
