/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:01:39 by zsyyida           #+#    #+#             */
/*   Updated: 2022/09/01 16:50:14 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list_char(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		ft_printf("number = %s and index = %d\n", (char *)(ptr->content),
			(ptr->index));
		ptr = ptr->next;
	}
	return ;
}
