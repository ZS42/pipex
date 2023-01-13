/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:20:53 by zsyyida           #+#    #+#             */
/*   Updated: 2023/01/02 14:42:42 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*path_env(char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i][j])
	{
		if (strncmp(&envp[i][j], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

// int access(const char *pathname, int how);
// pathname is the name of the file whose accessibility you want to test.
// The how argument indicates the access modes you want to test.
// The following symbols are defined in the unistd.h header file for
// use in the how argument:
// F_OK
// Tests whether the file exists.

void	free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free (paths);
}

char	*check_path(char *cmd, char **paths)
{
	int		i;
	char	*path_ok;

	i = 0;
	path_ok = NULL;
	while (paths[i])
	{
		paths[i] = ft_strjoin_ft(paths[i], cmd);
		if (access(paths[i], F_OK) == 0)
		{
			path_ok = ft_strdup_ft(paths[i]);
			break ;
		}
		i++;
	}
	free_path(paths);
	return (path_ok);
}

char	**append_path(char **envp)
{
	char	**paths;
	int		i;
	char	*find_path;
	char	*path;

	find_path = path_env(envp);
	path = ft_strtrim(find_path, "PATH=");
	paths = ft_split(path, ':');
	free (path);
	i = 0;
	while (paths[i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			paths[i] = ft_strjoin_ft (paths[i], "/");
		i++;
	}
	return (paths);
}

// ft_printf ("pathname is %s\n", valid_path);
char	*path(char *cmd, char **envp)
{
	char	**paths;
	char	*valid_path;

	paths = append_path(envp);
	valid_path = check_path(cmd, paths);
	if (valid_path)
		return (valid_path);
	else
		return (NULL);
}
