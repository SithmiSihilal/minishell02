/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_adapter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/11/17 11:31:11 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**copy_argv(char **argv)
{
	char	**new_argv;
	int		i;
	int		count;

	count = 0;
	while (argv && argv[count])
		count++;
	new_argv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_argv)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[count] = NULL;
	return (new_argv);
}

t_cmdlist	*cmd_to_cmdlist(t_cmd *cmd)
{
	t_cmdlist	*cmdlist;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (NULL);
	cmdlist = (t_cmdlist *)malloc(sizeof(t_cmdlist));
	if (!cmdlist)
		return (NULL);
	cmdlist->infile = 0;
	cmdlist->outfile = 1;
	cmdlist->pid = 0;
	cmdlist->heradoc_values = NULL;
	cmdlist->cmd = cmd->argv[0];
	cmdlist->path = copy_argv(cmd->argv);
	cmdlist->files = NULL;
	cmdlist->next = NULL;
	if (!cmdlist->path)
	{
		free(cmdlist);
		return (NULL);
	}
	return (cmdlist);
}

void	free_cmdlist_adapter(t_cmdlist *cmdlist)
{
	if (!cmdlist)
		return ;
	if (cmdlist->path)
		free(cmdlist->path);
	free(cmdlist);
}
