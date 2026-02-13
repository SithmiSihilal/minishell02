/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:16:27 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:09:01 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_type	token_type_from_str(const char *s)
{
	if (!s)
		return (TOKEN_WORD);
	if (s[0] == '|' && s[1] == '\0')
		return (TOKEN_PIPE);
	if (s[0] == '<' && s[1] == '\0')
		return (TOKEN_REDIR_IN);
	if (s[0] == '>' && s[1] == '\0')
		return (TOKEN_REDIR_OUT);
	if (s[0] == '>' && s[1] == '>' && s[2] == '\0')
		return (TOKEN_REDIR_APPEND);
	if (s[0] == '<' && s[1] == '<' && s[2] == '\0')
		return (TOKEN_HEREDOC);
	return (TOKEN_WORD);
}

static int	validate_pipe(t_token_iter *it, char **error)
{
	char	*next;

	next = it->parts[it->index + 1];
	if (it->index == 0 || !next || it->prev == TOKEN_PIPE
		|| token_is_redirect(it->prev))
	{
		if (next)
			token_set_error(error, "|");
		else
			token_set_error(error, NULL);
		return (0);
	}
	return (1);
}

static int	validate_redirect(t_token_iter *it, char **error)
{
	char			*next;
	t_token_type	next_type;

	next = it->parts[it->index + 1];
	if (!next)
	{
		token_set_error(error, NULL);
		return (0);
	}
	next_type = token_type_from_str(next);
	if (next_type != TOKEN_WORD)
	{
		token_set_error(error, next);
		return (0);
	}
	return (1);
}

static int	process_part(t_token_iter *it, t_token **head, char **error)
{
	t_token_type	current;

	current = token_type_from_str(it->parts[it->index]);
	if (current == TOKEN_PIPE)
	{
		if (!validate_pipe(it, error))
			return (0);
	}
	else if (token_is_redirect(current))
	{
		if (!validate_redirect(it, error))
			return (0);
	}
	if (!token_add_new(head, it->parts[it->index], current))
	{
		token_set_error(error, "allocation");
		return (0);
	}
	it->prev = current;
	return (1);
}

t_token	*tokenize(char **parts, char **error)
{
	t_token_iter	it;
	t_token			*head;

	it.parts = parts;
	it.index = 0;
	it.prev = TOKEN_PIPE;
	head = NULL;
	if (error)
		*error = NULL;
	while (parts && parts[it.index])
	{
		if (!process_part(&it, &head, error))
		{
			token_clear(&head);
			return (NULL);
		}
		it.index++;
	}
	return (head);
}
