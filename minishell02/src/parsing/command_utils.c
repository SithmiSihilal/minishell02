/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:27:52 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/01/11 14:34:00 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_argv(char **argv)
{
	size_t	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static void	free_redirs(t_redir *redir)
{
	t_redir	*next;

	while (redir)
	{
		next = redir->next;
		free(redir->target);
		free(redir);
		redir = next;
	}
}

void	cmd_clear(t_cmd **cmds)
{
	t_cmd	*next;

	if (!cmds)
		return ;
	while (*cmds)
	{
		next = (*cmds)->next;
		if ((*cmds)->argv)
			free_argv((*cmds)->argv);
		if ((*cmds)->redirs)
			free_redirs((*cmds)->redirs);
		if (*cmds)
			free(*cmds);
		*cmds = next;
	}
}
