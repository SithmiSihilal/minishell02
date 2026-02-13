/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:51:30 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:28:24 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isbuiltin(char *cmd)
{
	if (str_compare(cmd, "echo"))
		return (ECHO);
	else if (str_compare(cmd, "cd"))
		return (CD);
	else if (str_compare(cmd, "pwd"))
		return (PWD);
	else if (str_compare(cmd, "export"))
		return (EXPORT);
	else if (str_compare(cmd, "unset"))
		return (UNSET);
	else if (str_compare(cmd, "env"))
		return (ENV);
	else if (str_compare(cmd, "exit"))
		return (EXIT);
	return (0);
}

void	runbuiltin(t_core *core, t_cmdlist *cmdnode, int builtin)
{
	if (builtin == ECHO)
		runecho(cmdnode);
	else if (builtin == CD)
		runcd(core, cmdnode);
	else if (builtin == PWD)
		runpwd(cmdnode);
	else if (builtin == EXPORT)
		runexport(core, cmdnode);
	else if (builtin == UNSET)
		rununset(core, cmdnode);
	else if (builtin == ENV)
		runenv(core, cmdnode);
	else if (builtin == EXIT)
		runexit(core, cmdnode);
}
