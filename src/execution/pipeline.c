/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 16:21:33 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

int		count_cmds(t_cmd *cmd);
int		**create_pipes(int n_pipes);
void	close_all_pipes(int **pipes, int n_pipes);

static void	setup_pipe_fds(int i, int n_cmds, int **pipes)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < n_cmds - 1)
		dup2(pipes[i][1], STDOUT_FILENO);
	close_all_pipes(pipes, n_cmds - 1);
}

static void	exec_pipe_cmd(t_core *core, t_pipe_ctx *ctx)
{
	char	*path;
	int		status;

	setup_child_signals();
	setup_pipe_fds(ctx->cmd_i, ctx->n_cmds, ctx->pipes);
	if (ctx->cmd->redirs && apply_redirections(ctx->cmd->redirs,
			ctx->envp, core->exec_output) < 0)
		return (free_core(core), exit(1));
	if (isbuiltin(ctx->cmd->argv[0]))
	{
		status = execute_builtin_simple(core, ctx->cmd);
		return (free_core(core), exit(status));
	}
	path = find_in_path(ctx->cmd->argv[0], ctx->envp);
	if (!path)
	{
		printf("minishell: %s: command not found\n", ctx->cmd->argv[0]);
		free_core(core);
		exit(127);
	}
	execve(path, ctx->cmd->argv, ctx->envp);
	perror("minishell");
	free(path);
	free_core(core);
	exit(127);
}

static int	wait_pipeline(pid_t last_pid, int n_cmds)
{
	pid_t	pid;
	int		status;
	int		last_status;

	last_status = 0;
	while (n_cmds-- > 0)
	{
		pid = wait(&status);
		if (pid == last_pid && WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else if (pid == last_pid && WIFSIGNALED(status))
			last_status = 128 + WTERMSIG(status);
	}
	return (last_status);
}

static pid_t	fork_pipeline(t_core *core, t_pipe_ctx *ctx)
{
	pid_t	pid;
	pid_t	last_pid;

	last_pid = -1;
	while (ctx->cmd)
	{
		pid = fork();
		if (pid == 0)
			exec_pipe_cmd(core, ctx);
		last_pid = pid;
		ctx->cmd = ctx->cmd->next;
		ctx->cmd_i++;
	}
	return (last_pid);
}

int	execute_pipeline(t_core *core, t_cmd *first, char **envp)
{
	t_pipe_ctx	ctx;
	pid_t		last_pid;
	int			n_pipes;

	ctx.n_cmds = count_cmds(first);
	n_pipes = ctx.n_cmds - 1;
	ctx.pipes = create_pipes(n_pipes);
	core->pipes = ctx.pipes;
	core->n_pipes = n_pipes;
	if (!ctx.pipes && ctx.n_cmds > 1)
		return (1);
	ctx.cmd = first;
	ctx.envp = envp;
	ctx.cmd_i = 0;
	last_pid = fork_pipeline(core, &ctx);
	close_pipes(ctx.pipes, n_pipes);
	core->pipes = NULL;
	core->n_pipes = 0;
	return (wait_pipeline(last_pid, ctx.n_cmds));
}
