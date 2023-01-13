/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:08:49 by zsyyida           #+#    #+#             */
/*   Updated: 2023/01/12 16:34:07 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(int *fd)
{
	close (fd[0]);
	close (fd[1]);
	ft_printf("ERROR: %s\n", strerror(errno));
	exit (0);
}
