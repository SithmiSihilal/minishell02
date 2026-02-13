/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 16:22:21 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

int	handle_heredoc(const char *delimiter, char **envp, int exit_status);

static int	open_and_dup(const char *file, int flags, int mode, int target)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd < 0)
	{
		perror("minishell");
		return (-1);
	}
	if (dup2(fd, target) < 0)
	{
		close(fd);
		perror("minishell");
		return (-1);
	}
	close(fd);
	return (0);
}

static int	handle_input_redir(const char *file)
{
	return (open_and_dup(file, O_RDONLY, 0, STDIN_FILENO));
}

static int	handle_output_redir(const char *file)
{
	return (open_and_dup(file, O_WRONLY | O_CREAT | O_TRUNC, 0644,
			STDOUT_FILENO));
}

static int	handle_append_redir(const char *file)
{
	return (open_and_dup(file, O_WRONLY | O_CREAT | O_APPEND, 0644,
			STDOUT_FILENO));
}

int	apply_redirections(t_redir *redirs, char **envp, int exit_status)
{
	t_redir	*current;
	int		result;

	current = redirs;
	while (current)
	{
		if (current->type == TOKEN_REDIR_IN)
			result = handle_input_redir(current->target);
		else if (current->type == TOKEN_REDIR_OUT)
			result = handle_output_redir(current->target);
		else if (current->type == TOKEN_REDIR_APPEND)
			result = handle_append_redir(current->target);
		else if (current->type == TOKEN_HEREDOC)
			result = handle_heredoc(current->target, envp, exit_status);
		else
			result = 0;
		if (result < 0)
			return (-1);
		current = current->next;
	}
	return (0);
}
