/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:20:32 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:30:21 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *var_name, char **envp, int exit_status)
{
	size_t	i;
	size_t	len;

	if (!var_name)
		return (ft_strdup(""));
	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(exit_status));
	len = ft_strlen(var_name);
	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], var_name, len) == 0
			&& envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

char	*extract_var_name(const char *str, size_t *len)
{
	size_t	i;
	char	*name;

	if (!str || str[0] != '$')
		return (NULL);
	if (str[1] == '?')
		return (*len = 2, ft_strdup("?"));
	i = 1;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (*len = 1, ft_strdup(""));
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	*len = i;
	name = malloc(i);
	if (!name)
		return (NULL);
	ft_strlcpy(name, str + 1, i);
	return (name);
}

static void	process_quote_char(const char *str, size_t *ij, char *in_quote,
		int *quote_mode)
{
	if ((str[ij[0]] == '\'' || str[ij[0]] == '\"') && !*in_quote)
	{
		*in_quote = str[ij[0]];
		if (str[ij[0]] == '\'')
			*quote_mode = 1;
		else
			*quote_mode = 2;
	}
	else if (str[ij[0]] == *in_quote)
		*in_quote = 0;
	else
		ij[1]++;
}

char	*remove_quotes_and_get_mode(const char *str, int *quote_mode)
{
	size_t	ij[2];
	char	*result;
	char	in_quote;

	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	ij[0] = 0;
	ij[1] = 0;
	in_quote = 0;
	*quote_mode = 0;
	while (str[ij[0]])
	{
		if ((str[ij[0]] != '\'' && str[ij[0]] != '\"') || in_quote)
			if (str[ij[0]] != in_quote)
				result[ij[1]] = str[ij[0]];
		process_quote_char(str, ij, &in_quote, quote_mode);
		ij[0]++;
	}
	result[ij[1]] = '\0';
	return (result);
}
