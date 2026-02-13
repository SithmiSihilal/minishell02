/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:04:20 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:11:32 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isspecialchar(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

int	get_quote_closing_idx(t_split_ctx *ctx, char *input, int *start_idx)
{
	char	quote;
	int		i;

	quote = input[*start_idx];
	i = *start_idx + 1;
	while (input[i])
	{
		if (input[i] == quote)
		{
			*start_idx = i;
			return (i);
		}
		i++;
	}
	ctx->quote_error = quote;
	return (-1);
}

int	is_generic_word(char current, char next)
{
	return (((!ft_isspace(current) && !ft_isspecialchar(current))
			&& (ft_isspace(next)
				|| next == '\0'
				|| ft_isspecialchar(next)
				|| (current == '\'' && next == '"')
			)));
}
