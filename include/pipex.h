/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:36:30 by zsyyida           #+#    #+#             */
/*   Updated: 2023/01/13 12:43:59 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <stdlib.h> // to use exit
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h> // to use waitpid() wait()
// to find procees id of child and parent
// main process id is zero (but when check id = 0 get parents id of child
// process

typedef struct s_pipex
{
	char	*path;
	char	*cmd;
	char	*file_in;
	char	*file_out;
	int		fd_in;
	int		fd_out;
}	t_pipex;

int		main(int ac, char **argv, char **envp);
char	*path_env(char **envp);
char	**append_path(char **envp);
char	*check_path(char *cmd, char **paths);
char	*path(char *cmd, char **envp);
int		pipex(char **av, char **envp);
int		child_process1(char **av, char **envp, int *fd);
int		child_process2(char **av, char **envp, int *fd);
void	free_split(char *cmd_path, char **cmd);
int		error(int *fd);

#endif
