/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:40:50 by siellage          #+#    #+#             */
/*   Updated: 2026/02/13 15:12:01 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isallnumeric(char *text)
{
	int	i;

	i = 0;
	if (text[i] == '-' || text[i] == '+')
		i++;
	if (!text[i])
		return (0);
	while (text[i])
	{
		if (text[i] < '0' || text[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	cleanup_and_exit(t_core *core, t_cmdlist *cmdnode, int exit_code)
{
	free_core(core);
	free_cmdlist_adapter(cmdnode);
	close(core->saved_stdin);
	close(core->saved_stdout);
	exit(exit_code);
}

static int	get_exit_code(t_cmdlist *cmdnode)
{
	if (!isallnumeric(cmdnode->path[1]))
	{
		print_error("-bash: exit: ", cmdnode->path[1],
			": numeric argument required\n");
		return (2);
	}
	return (ft_atoi(cmdnode->path[1]));
}

void	runexit(t_core *core, t_cmdlist *cmdnode)
{
	int		exit_code;
	int		arraylen;

	exit_code = core->exec_output;
	arraylen = getarraylen(cmdnode->path);
	if (arraylen > 2)
	{
		if (!isallnumeric(cmdnode->path[1]))
		{
			print_error("-bash: exit: ", cmdnode->path[1],
				": numeric argument required\n");
				cleanup_and_exit(core, cmdnode, 2);
		}
		print_error("exit\n-bash: exit: too many arguments\n", NULL, NULL);
		core->exec_output = 1;
		return ;
	}
	write(1, "exit\n", 5);
	if (arraylen == 2)
		exit_code = get_exit_code(cmdnode);
	cleanup_and_exit(core, cmdnode, exit_code);
}
