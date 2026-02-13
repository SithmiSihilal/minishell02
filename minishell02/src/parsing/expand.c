/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:06:22 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 17:16:33 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*process_single_quote(const char *str, size_t *i, char *res)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		res = join_char_free(res, str[*i]);
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (res);
}

static char	*process_double_quote(const char *str, size_t *i, char *res,
		t_expand_ctx *ctx)
{
	(*i)++;
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
			res = handle_dollar(str, i, res, ctx);
		else
			res = join_char_free(res, str[(*i)++]);
	}
	if (str[*i] == '\"')
		(*i)++;
	return (res);
}

static char	*process_unquoted(const char *str, size_t *i, char *res,
		t_expand_ctx *ctx)
{
	if (str[*i] == '$')
		res = handle_dollar(str, i, res, ctx);
	else
		res = join_char_free(res, str[(*i)++]);
	return (res);
}

static char	*expand_and_remove_quotes(const char *str, t_expand_ctx *ctx)
{
	size_t	i;
	char	*res;

	if (!str)
		return (NULL);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			res = process_single_quote(str, &i, res);
		else if (str[i] == '\"')
			res = process_double_quote(str, &i, res, ctx);
		else
			res = process_unquoted(str, &i, res, ctx);
	}
	return (res);
}

void	expand_tokens(t_token *tokens, char **envp, int exit_status)
{
	t_token			*curr;
	char			*expanded;
	t_expand_ctx	ctx;

	ctx.envp = envp;
	ctx.exit_status = exit_status;
	curr = tokens;
	while (curr)
	{
		if (curr->type == TOKEN_WORD && curr->value)
		{
			expanded = expand_and_remove_quotes(curr->value, &ctx);
			if (expanded)
			{
				free(curr->value);
				curr->value = expanded;
			}
		}
		curr = curr->next;
	}
}
