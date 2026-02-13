/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:45:13 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:09:10 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_is_redirect(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_REDIR_APPEND || type == TOKEN_HEREDOC);
}

int	token_set_error(char **error, const char *token)
{
	if (!error)
		return (0);
	if (*error)
	{
		free(*error);
		*error = NULL;
	}
	if (!token)
		token = "newline";
	*error = ft_strdup(token);
	return (*error != NULL);
}
