/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:33:28 by siellage          #+#    #+#             */
/*   Updated: 2026/02/13 17:41:24 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	runenv(t_core *core, t_cmdlist *cmdnode)
{
	t_env	*tempenv;
	int		argc;

	argc = getarraylen(cmdnode->path);
	if (argc > 1)
	{
		print_error("env: ", "too many arguments\n", NULL);
		core->exec_output = 1;
		return ;
	}
	tempenv = core->env_table;
	while (tempenv)
	{
		if (tempenv->content)
		{
			write(cmdnode->outfile, tempenv->env_name,
				ft_strlen(tempenv->env_name));
			write(cmdnode->outfile, "=", 1);
			write(cmdnode->outfile, tempenv->content,
				ft_strlen(tempenv->content));
			write(cmdnode->outfile, "\n", 1);
		}
		tempenv = tempenv->next;
	}
}
