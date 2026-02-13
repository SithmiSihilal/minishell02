/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:28 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_array_len(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}

int	is_all_numeric(char *text)
{
	while (text && *text)
	{
		if (!(*text >= '0' && *text <= '9'))
			return (0);
		text++;
	}
	return (1);
}

int	env_arg_control(t_core *core, char *env)
{
	if (envnamecontrol(env))
		return (1);
	print_error("-bash: export: `", env, "': not a valid identifier\n");
	core->exec_output = 1;
	return (0);
}

static t_env	*create_env_node(char *envcmd)
{
	t_env	*new;
	char	*envname;
	char	*content;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	envname = getenvname(envcmd);
	new->env_name = envname;
	content = envnamecontrol(envcmd);
	if (content && *content)
		new->content = ft_strdup(content);
	else
		new->content = NULL;
	new->next = NULL;
	return (new);
}

void	add_newenv(t_core *core, t_env **env, char *envcmd)
{
	t_env	*new;
	t_env	*temp;

	new = create_env_node(envcmd);
	if (!new)
		return ;
	if (!*env)
	{
		*env = new;
		core->env_table = new;
		return ;
	}
	temp = *env;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
