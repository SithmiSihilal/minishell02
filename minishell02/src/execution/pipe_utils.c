/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:35:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/01/30 13:11:24 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		count++;
		cmd = cmd->next;
	}
	return (count);
}

void	close_pipes(int **pipes, int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		if (pipes[i])
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
			free(pipes[i]);
		}
		i++;
	}
	free(pipes);
}

int	**create_pipes(int n_pipes)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * n_pipes);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < n_pipes)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) == -1)
		{
			while (--i >= 0)
				free(pipes[i]);
			free(pipes);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	close_all_pipes(int **pipes, int n_pipes)
{
	int	j;

	j = 0;
	while (j < n_pipes)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}
