/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:32:04 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:29:46 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	updatepwdfromexport(t_core *core, char *pwdname, char *pwdcontent)
{
	char	*temppwd;

	if (!updateenv(core, pwdname, pwdcontent))
	{
		temppwd = NULL;
		ownstrjoin(&temppwd, pwdname);
		straddchar(&temppwd, '=');
		ownstrjoin(&temppwd, pwdcontent);
		addnewenv(&core->env_table, temppwd);
		free(temppwd);
		return (0);
	}
	return (1);
}

int	changedir(t_core *core, char *path)
{
	char	pwd[256];
	int		ispwdaccess;
	char	*oldpwd;
	int		error;

	oldpwd = ft_strdup(getcwd(pwd, 256));
	error = chdir(path);
	if (error == -1)
	{
		if (oldpwd)
			free(oldpwd);
		return (0);
	}
	ispwdaccess = updatepwdfromexport(core, "PWD", getcwd(pwd, 256));
	if (ispwdaccess)
		updatepwdfromexport(core, "OLDPWD", oldpwd);
	else
		deleteenv(core, "OLDPWD");
	if (oldpwd)
		free(oldpwd);
	sync_my_env(core);
	changetitle();
	return (1);
}
