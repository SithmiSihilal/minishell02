/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_adapter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:30:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 15:23:05 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdlist	*cmd_to_cmdlist(t_cmd *cmd);
void		free_cmdlist_adapter(t_cmdlist *cmdlist);

static void	restore_fds(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}

static int	run_builtin_cmd(t_core *core, t_cmd *cmd)
{
	t_cmdlist	*cmdlist;
	int			builtin_type;
	int			status;

	status = 0;
	cmdlist = cmd_to_cmdlist(cmd);
	if (cmdlist)
	{
		builtin_type = isbuiltin(cmd->argv[0]);
		if (builtin_type)
			runbuiltin(core, cmdlist, builtin_type);
		free_cmdlist_adapter(cmdlist);
	}
	status = core->exec_output;
	return (status);
}

int	execute_builtin_simple(t_core *core, t_cmd *cmd)
{
	int	saved_stdin;
	int	saved_stdout;
	int	status;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	core->saved_stdin = saved_stdin;
	core->saved_stdout = saved_stdout;
	if (cmd->redirs && apply_redirections(cmd->redirs,
			core->my_env, core->exec_output) < 0)
	{
		restore_fds(saved_stdin, saved_stdout);
		return (1);
	}
	status = run_builtin_cmd(core, cmd);
	restore_fds(saved_stdin, saved_stdout);
	return (status);
}
