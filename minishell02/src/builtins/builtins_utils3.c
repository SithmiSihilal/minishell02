/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/01/30 15:09:51 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_cmd_node(t_cmdlist *cmd)
{
	if (cmd->heradoc_values)
		free(cmd->heradoc_values);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}

void	free_for_loop(t_core *core)
{
	t_cmdlist	*cmd;
	t_cmdlist	*next;

	cmd = core->cmd_table;
	while (cmd)
	{
		next = cmd->next;
		free_cmd_node(cmd);
		cmd = next;
	}
}

static void	free_env_node(t_env *env)
{
	if (env->env_name)
		free(env->env_name);
	if (env->content)
		free(env->content);
	free(env);
}

void	free_list_env(t_env *env)
{
	t_env	*next;

	while (env)
	{
		next = env->next;
		free_env_node(env);
		env = next;
	}
}

void	free_core(t_core *core)
{
	if (core->cmd)
		free(core->cmd);
	if (core->metachars)
		free(core->metachars);
	free_list_env(core->env_table);
	freeenvcpy(core->my_env);
	cmd_clear(&core->cmds);
	if (core->pipes && core->n_pipes > 0)
		close_pipes(core->pipes, core->n_pipes);
	core->pipes = NULL;
	core->n_pipes = 0;
	free_cmdlist_adapter(core->cmd_table);
}
