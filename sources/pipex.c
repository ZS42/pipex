/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:20:50 by zsyyida           #+#    #+#             */
/*   Updated: 2023/01/12 16:34:31 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_split(char *cmd_path, char **cmd)
{
	int	i;

	i = 0;
	if (cmd_path != NULL)
		free(cmd_path);
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free (cmd);
	ft_printf("ERROR: %s\n", strerror(errno));
}

// ft_printf("%s\n", cmd[0]);
// ft_printf("----%s----\n", cmd_path);
int	child_process2(char **av, char **envp, int *fd)
{
	char	*cmd_path;
	int		fd_outfile;
	char	**cmd;

	cmd = ft_split(av[3], ' ');
	cmd_path = path(cmd[0], envp);
	fd_outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_outfile == -1)
		free_split(cmd_path, cmd);
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	dup2(fd_outfile, STDOUT_FILENO);
	close (fd_outfile);
	if (cmd_path != NULL && cmd != NULL)
		execve(cmd_path, cmd, envp);
	free_split(cmd_path, cmd);
	return (0);
}

// ft_printf("%s\n", cmd[0]);
// ft_printf("----%s----\n", cmd_path);
// exec functions replace childprocess so nothing can happen
// in that process after them
// but exec doesnt change open files or fds
// dup2 takes file you want to duplicate as first arg
// and what you want the new file descriptor value as second
int	child_process1(char **av, char **envp, int *fd)
{
	char	*cmd_path;
	int		fd_infile;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	cmd_path = path(cmd[0], envp);
	fd_infile = open(av[1], O_RDONLY, 0777);
	if (fd_infile == -1)
		free_split(cmd_path, cmd);
	close (fd[0]);
	dup2(fd_infile, STDIN_FILENO);
	close (fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]);
	if (cmd_path != NULL && cmd != NULL)
		execve(cmd_path, cmd, envp);
	free_split(cmd_path, cmd);
	return (0);
}

// int	status;
// check for closing all pipes if error before return
// wait(&status); should only be used if single child
// else paren will end after waiting for one child executed
// and other children left hanging but can use with condition
// while(wait(NULL) != 1 && errno != ECHILD)
// in this case will wait till all child processes have executed
// wait(NULL) returns -1 when nothing to wait for
// need to make sure not another error use errno != ECHILD
// [ECHILD] Calling process has no remaining child processes
// on which wait operation can be performed.

// close parents file descriptors before wait
// dont really need to fork only from parent as forking after
// child1 executed

	// if (WIFEXITED(wstatus))
	// {
	// 	if (statusCode == 0)
	// 		ft_printf("Sucess!\n");
	// 	else
	// 		ft_printf("Failure with status code %d\n", statusCode);
	// }

// int	statusCode;

int	pipex(char **av, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	pid1 = 0;
	pid2 = 0;
	if (pipe (fd) == -1 || fd[0] == -1 || fd[1] == -1)
		error(fd);
	pid1 = fork();
	if (pid1 == -1)
		error(fd);
	if (pid1 == 0)
		child_process1(av, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		error(fd);
	if (pid2 == 0)
		child_process2(av, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
