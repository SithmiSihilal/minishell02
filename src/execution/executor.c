/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 15:42:37 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

int	is_directory(const char *path)
{
	DIR	*dir;

	if (!path)
		return (0);
	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		write(2, "Minishell: ", 11);
		write(2, path, ft_strlen(path));
		write(2, ": Is a directory\n", 17);
		return (1);
	}
	return (0);
}

static void	exec_child(t_core *core, char *path, t_cmd *cmd, char **envp)
{
	signal(SIGINT, SIG_IGN);
	if (cmd->redirs && apply_redirections(cmd->redirs, envp,
			core->exec_output) < 0)
	{
		free(path);
		free_core(core);
		exit(1);
	}
	if (is_directory(path))
	{
		free(path);
		free_core(core);
		exit(126);
	}
	setup_child_signals();
	execve(path, cmd->argv, envp);
	free(path);
	free_core(core);
	exit(127);
}

static int	wait_child(pid_t pid)
{
	int	status;
	int	signal;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		status = 1;
		if (signal == SIGQUIT)
		{
			write(STDERR_FILENO, "Quit (core dumped)\n", 19);
			status = 131;
		}
		else if (signal == SIGINT)
			status = 130;
	}
	return (status);
}

int	execute_external(t_core *core, t_cmd *cmd, char **envp)
{
	pid_t	pid;
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (1);
	path = find_in_path(cmd->argv[0], envp);
	if (!path)
	{
		printf("minishell: %s: command not found\n", cmd->argv[0]);
		return (127);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (free(path), 1);
	if (pid == 0)
		exec_child(core, path, cmd, envp);
	free(path);
	return (wait_child(pid));
}
