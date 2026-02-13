/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:01:55 by siellage          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:39 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	createdup(t_core *core, t_cmdlist *cmd_list, int *fd, int fdindex)
{
	int	newfd[2];

	if (cmd_list->infile == HERADOC)
	{
		pipe(newfd);
		write(newfd[1], cmd_list->heradoc_values,
			ft_strlen(cmd_list->heradoc_values));
		dup2(newfd[0], STDIN_FILENO);
		close (newfd[1]);
		close(newfd[0]);
	}
	else if (cmd_list->infile > SSTDERR)
		dup2(cmd_list->infile, STDIN_FILENO);
	else if (fd && cmd_list != core->cmd_table)
		dup2(fd[fdindex - 2], STDIN_FILENO);
	if (cmd_list->outfile > SSTDERR)
		dup2(cmd_list->outfile, STDOUT_FILENO);
	else if (fd && cmd_list->next)
		dup2(fd[fdindex + 1], STDOUT_FILENO);
	if (fdindex >= 0)
		clearpipe(fd);
}
