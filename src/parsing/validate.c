/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:03:41 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:08:43 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_unsupported_char(char c)
{
	return (c == ';' || c == '\\' || c == '&');
}

int	validate_input(const char *input)
{
	size_t	i;
	char	quote;

	if (!input)
		return (1);
	i = 0;
	quote = 0;
	while (input[i])
	{
		if ((input[i] == '\'' || input[i] == '\"') && !quote)
			quote = input[i];
		else if (input[i] == quote)
			quote = 0;
		else if (!quote && is_unsupported_char(input[i]))
		{
			printf("minishell: syntax error near unexpected token `%c'\n",
				input[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
