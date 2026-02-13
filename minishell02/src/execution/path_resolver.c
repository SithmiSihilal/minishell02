/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:30:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 15:27:55 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_executable(const char *path)
{
	int			fd;

	if (access(path, F_OK | X_OK) == 0)
	{
		fd = open(path, O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			return (0);
		}
		return (1);
	}
	return (0);
}

static char	*try_path(const char *dir, const char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!full_path)
		return (NULL);
	if (is_executable(full_path))
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_in_path(const char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*result;
	int		i;

	if (!cmd || !envp)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_var_value("PATH", envp, 0);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	free(path_env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		result = try_path(paths[i], cmd);
		if (result)
			return (free_env(paths), result);
		i++;
	}
	return (free_env(paths), NULL);
}
