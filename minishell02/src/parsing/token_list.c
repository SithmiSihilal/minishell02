/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:14:51 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:09:17 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*token_new(char *value, t_token_type type)
{
	t_token	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	if (!node->value)
	{
		free(node);
		return (NULL);
	}
	node->type = type;
	node->next = NULL;
	return (node);
}

static t_token	*token_last(t_token *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	token_add_new(t_token **tokens, char *value, t_token_type type)
{
	t_token	*node;
	t_token	*last;

	if (!tokens || !value)
		return (0);
	node = token_new(value, type);
	if (!node)
		return (0);
	if (!*tokens)
	{
		*tokens = node;
		return (1);
	}
	last = token_last(*tokens);
	last->next = node;
	return (1);
}

void	token_clear(t_token **tokens)
{
	t_token	*tmp;

	if (!tokens)
		return ;
	while (*tokens)
	{
		tmp = (*tokens)->next;
		free((*tokens)->value);
		free(*tokens);
		*tokens = tmp;
	}
}
