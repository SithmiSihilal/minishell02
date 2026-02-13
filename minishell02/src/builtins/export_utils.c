/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:40:50 by siellage          #+#    #+#             */
/*   Updated: 2026/01/11 14:30:13 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_vars(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

void	sort_env_array(t_env **arr, int len)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (ft_strcmp(arr[j]->env_name, arr[j + 1]->env_name) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_export_var(t_env *env, int fd)
{
	write(fd, "declare -x ", 11);
	write(fd, env->env_name, ft_strlen(env->env_name));
	if (!env->content)
	{
		write(fd, "\n", 1);
		return ;
	}
	write(fd, "=\"", 2);
	write(fd, env->content, ft_strlen(env->content));
	write(fd, "\"\n", 2);
}

int	changeenv(t_core *core, char *envname, char *arg, int isequal)
{
	t_env	*env;

	env = core->env_table;
	while (env)
	{
		if (str_compare(envname, env->env_name))
		{
			if (isequal)
				updateenv(core, envname, arg);
			return (1);
		}
		env = env->next;
	}
	return (0);
}
