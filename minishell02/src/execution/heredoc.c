/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 16:58:37 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_var_in_line(char *line, char **envp, int exit_status)
{
	char	*result;
	char	*vn;
	size_t	i;
	size_t	vl;

	result = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			vn = extract_var_name(line + i, &vl);
			if (vn && vn[0])
				result = join_str_free(result,
						get_var_value(vn, envp, exit_status));
			else
				result = join_char_free(result, '$');
			free(vn);
			i += vl;
		}
		else
			result = join_char_free(result, line[i++]);
	}
	free(line);
	return (result);
}

static void	heredoc_loop(int write_fd, const char *delim, char **e, int es)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		line = expand_var_in_line(line, e, es);
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
}

int	handle_heredoc(const char *delimiter, char **envp, int exit_status)
{
	int		pipefd[2];

	signal(SIGINT, handle_sigint);
	if (pipe(pipefd) < 0)
		return (perror("minishell"), -1);
	heredoc_loop(pipefd[1], delimiter, envp, exit_status);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		return (close(pipefd[0]), perror("minishell"), -1);
	close(pipefd[0]);
	return (0);
}
