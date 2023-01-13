/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:49:37 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/03 12:18:17 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_printf("int = %d and index = %d\n", *(int *)ptr->content, ptr->index);
void	ft_print_list_int(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
	}
	ft_printf("\n");
	return ;
}
