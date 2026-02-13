/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_adapter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/12/19 10:42:09 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*create_env_from_str(char *env_str)
{
	t_env	*new;
	char	*equal;
	int		name_len;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	equal = ft_strchr(env_str, '=');
	if (equal)
	{
		name_len = equal - env_str;
		new->env_name = ft_substr(env_str, 0, name_len);
		new->content = ft_strdup(equal + 1);
	}
	else
	{
		new->env_name = ft_strdup(env_str);
		new->content = NULL;
	}
	new->next = NULL;
	return (new);
}

static void	add_env_nodes(t_env *head, char **envp)
{
	t_env	*current;
	int		i;

	current = head;
	i = 1;
	while (envp[i])
	{
		current->next = create_env_from_str(envp[i]);
		if (!current->next)
			break ;
		current = current->next;
		i++;
	}
}

void	init_global_env(t_core *core, char **envp)
{
	t_env	*head;

	if (!envp || !envp[0])
	{
		core->env_table = NULL;
		return ;
	}
	head = create_env_from_str(envp[0]);
	if (!head)
	{
		core->env_table = NULL;
		return ;
	}
	add_env_nodes(head, envp);
	core->env_table = head;
	core->exec_output = 0;
}
