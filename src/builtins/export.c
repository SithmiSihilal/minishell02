/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:40:50 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:30:13 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_env_vars(t_env *env);
void	sort_env_array(t_env **arr, int len);
void	print_export_var(t_env *env, int fd);

int	runexport(t_core *core, t_cmdlist *cmdnode)
{
	int		arraylen;
	char	**temppath;

	core->exec_output = 0;
	arraylen = getarraylen(cmdnode->path);
	if (arraylen > 1)
	{
		temppath = cmdnode->path;
		while (*(++temppath))
			doubleexportarg(core, *temppath);
		sync_my_env(core);
	}
	else
		singleexportarg(core, cmdnode);
	return (core->exec_output);
}

void	singleexportarg(t_core *core, t_cmdlist *cmdnode)
{
	t_env	**arr;
	t_env	*env;
	int		len;
	int		i;

	len = count_env_vars(core->env_table);
	if (len == 0)
		return ;
	arr = malloc(sizeof(t_env *) * len);
	if (!arr)
		return ;
	env = core->env_table;
	i = 0;
	while (env)
	{
		arr[i++] = env;
		env = env->next;
	}
	sort_env_array(arr, len);
	i = 0;
	while (i < len)
		print_export_var(arr[i++], cmdnode->outfile);
	free(arr);
}

void	doubleexportarg(t_core *core, char *envcmd)
{
	char	*arg;
	int		isequal;
	char	*tempenvname;

	if (!envargcontrol(core, envcmd, 1))
		return ;
	tempenvname = getenvname(envcmd);
	arg = envcmd + ft_strlen(tempenvname);
	isequal = 0;
	if (*arg == '=')
		isequal |= 1;
	if (changeenv(core, tempenvname, ++arg, isequal))
	{
		free(tempenvname);
		return ;
	}
	addnewenv(&core->env_table, envcmd);
	if (!isequal)
		updateenv(core, envcmd, NULL);
	free(tempenvname);
}
