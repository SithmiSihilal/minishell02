/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:06:22 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 16:36:00 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_str_free(char *res, char *val)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin(res, val);
	free(val);
	free(tmp);
	return (res);
}

static char	*join_char_free(char *res, char c)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin_char(res, c);
	free(tmp);
	return (res);
}

static char	*process_single_quote(const char *str, size_t *i, char *result)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		result = join_char_free(result, str[*i]);
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (result);
}

static char	*process_double_quote(const char *str, size_t *i, char *result,
		char **envp, int exit_status)
{
	size_t	vl;
	char	*vn;

	(*i)++;
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] == '$')
		{
			vn = extract_var_name(str + *i, &vl);
			if (vn && vn[0])
				result = join_str_free(result, get_var_value(vn, envp, exit_status));
			else if (!vn || !vn[0])
				result = join_char_free(result, '$');
			free(vn);
			*i += vl;
		}
		else
			result = join_char_free(result, str[(*i)++]);
	}
	if (str[*i] == '\"')
		(*i)++;
	return (result);
}

static char	*process_unquoted(const char *str, size_t *i, char *result,
		char **envp, int exit_status)
{
	size_t	vl;
	char	*vn;

	if (str[*i] == '$')
	{
		vn = extract_var_name(str + *i, &vl);
		if (vn && vn[0])
			result = join_str_free(result, get_var_value(vn, envp, exit_status));
		else if (!vn || !vn[0])
			result = join_char_free(result, '$');
		free(vn);
		*i += vl;
	}
	else
		result = join_char_free(result, str[(*i)++]);
	return (result);
}

static char	*expand_and_remove_quotes(const char *str, char **envp, int exit_status)
{
	size_t	i;
	char	*result;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			result = process_single_quote(str, &i, result);
		else if (str[i] == '\"')
			result = process_double_quote(str, &i, result, envp, exit_status);
		else
			result = process_unquoted(str, &i, result, envp, exit_status);
	}
	return (result);
}

void	process_word_token(t_token *token, char **envp, int exit_status)
{
	char	*expanded;

	if (!token || !token->value)
		return ;
	expanded = expand_and_remove_quotes(token->value, envp, exit_status);
	if (expanded)
	{
		free(token->value);
		token->value = expanded;
	}
}

void	expand_tokens(t_token *tokens, char **envp, int exit_status)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_WORD && current->value)
			process_word_token(current, envp, exit_status);
		current = current->next;
	}
}
