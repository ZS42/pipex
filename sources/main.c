/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:41:29 by zsyyida           #+#    #+#             */
/*   Updated: 2023/01/13 12:48:26 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// fd[0] is read end of pipe
// fd[1] is write end of pipe
// in linux fd of STDOUT (here opened by dup2)
// automatically closes after execution
// until all write fd's are closed the processes will wait
int	main(int ac, char **av, char **envp)
{
	if (ac < 5 || ac > 5)
		return (1);
	if (ac == 5)
		pipex(av, envp);
}
