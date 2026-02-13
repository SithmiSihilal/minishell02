/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:32:40 by siellage          #+#    #+#             */
/*   Updated: 2025/12/19 11:11:15 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getarraylen(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}

void	print_error(char *ptr1, char *ptr2, char *ptr3)
{
	if (ptr1)
		write(2, ptr1, ft_strlen(ptr1));
	if (ptr2)
		write(2, ptr2, ft_strlen(ptr2));
	if (ptr3)
		write(2, ptr3, ft_strlen(ptr3));
}

void	changetitle(void)
{
	return ;
}

int	updateenv(t_core *core, char *envname, char *newarg)
{
	t_env	*env;

	env = core->env_table;
	while (env)
	{
		if (str_compare(env->env_name, envname))
		{
			if (env->content)
				free(env->content);
			env->content = NULL;
			if (!newarg)
				return (1);
			ownstrjoin(&env->content, newarg);
			return (1);
		}
		env = env->next;
	}
	return (0);
}
