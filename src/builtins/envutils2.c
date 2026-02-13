/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:06:23 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:18:17 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getenvname(char *content)
{
	int		envnamelen;
	char	*name;
	char	*tempname;

	envnamelen = getenvnamecount(content);
	if (!envnamelen)
		return (NULL);
	name = (char *)malloc(sizeof(char) * (envnamelen + 1));
	tempname = name;
	while (content && *content && *content != '=')
		*(tempname++) = *(content++);
	*tempname = 0;
	return (name);
}

int	getenvnamecount(char *env_arg)
{
	int	count;

	count = 0;
	while (env_arg && *env_arg && *(env_arg++) != '=')
		count++;
	return (count);
}

char	*validenv(char *env)
{
	int	flag;

	flag = 0;
	if ((*env >= 'a' && *env <= 'z') || (*env >= 'A' && *env <= 'Z'))
		flag = 1;
	while (*env != ' ' && *env && *env != '=')
	{
		if ((*env > '0' && *env < '9' && !flag)
			|| compare_metachars(env))
			return (NULL);
		env++;
	}
	return (env);
}

char	*envnamecontrol(char *env)
{
	char	*envtemp;

	if (!env || *env == ' ' || *env == '=')
		return (NULL);
	envtemp = env;
	envtemp = validenv(envtemp);
	if (!envtemp || (*envtemp != '=' && *envtemp))
		return (NULL);
	if (*envtemp == '=')
		return (++envtemp);
	else
		return (envtemp);
}

int	envargcontrol(t_core *core, char *env, int print)
{
	if (envnamecontrol(env))
		return (1);
	if (print)
		print_error("-bash: export: `", env, "': not a valid identifier\n");
	core->exec_output = 1;
	return (0);
}
