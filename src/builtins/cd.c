/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:32:04 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:29:46 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	runcd(t_core *core, t_cmdlist *cmdnode)
{
	int		arraylen;

	arraylen = getarraylen(cmdnode->path);
	if (arraylen > 2)
	{
		core->exec_output = 1;
		print_error("-bash: cd: too many arguments\n", NULL, NULL);
	}
	else if (arraylen == 2)
		cddoublearg(core, cmdnode);
	else
		cdsinglearg(core);
}

void	cdsinglearg(t_core *core)
{
	t_env	*tempenv;
	char	*content;

	tempenv = core->env_table;
	while (tempenv)
	{
		if (str_compare("HOME", tempenv->env_name))
		{
			content = tempenv->content;
			if (!content)
				return ;
			changedir(core, content);
			return ;
		}
		tempenv = tempenv->next;
	}
	print_error("-bash: cd: HOME not set\n", NULL, NULL);
	core->exec_output |= 1;
}

static char	*get_oldpwd(t_core *core)
{
	t_env	*env;

	env = core->env_table;
	while (env)
	{
		if (str_compare("OLDPWD", env->env_name))
			return (env->content);
		env = env->next;
	}
	return (NULL);
}

static void	cd_to_oldpwd(t_core *core)
{
	char	*oldpwd;

	oldpwd = get_oldpwd(core);
	if (!oldpwd)
	{
		print_error("-bash: cd: OLDPWD not set\n", NULL, NULL);
		core->exec_output = 1;
		return ;
	}
	oldpwd = ft_strdup(oldpwd);
	if (!oldpwd)
		return ;
	if (changedir(core, oldpwd))
		printf("%s\n", oldpwd);
	free(oldpwd);
}

void	cddoublearg(t_core *core, t_cmdlist *cmdnode)
{
	if (strcmp(cmdnode->path[1], "~") == 0)
		cdsinglearg(core);
	else if (strcmp(cmdnode->path[1], "-") == 0)
		cd_to_oldpwd(core);
	else if (!changedir(core, cmdnode->path[1]))
	{
		print_error("-bash: cd: ", cmdnode->path[1],
			": No such file or directory\n");
		core->exec_output = 1;
	}
}
