/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:00 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/11/17 11:28:54 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_compare(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

int	compare_metachars(char *str)
{
	if (!str)
		return (0);
	if (*str == '!' || *str == '@' || *str == '#' || *str == '$')
		return (1);
	if (*str == '%' || *str == '^' || *str == '&' || *str == '*')
		return (1);
	if (*str == '(' || *str == ')' || *str == '-' || *str == '+')
		return (1);
	if (*str == '=' || *str == '{' || *str == '}' || *str == '[')
		return (1);
	if (*str == ']' || *str == '|' || *str == '\\' || *str == ':')
		return (1);
	if (*str == ';' || *str == '\'' || *str == '"' || *str == '<')
		return (1);
	if (*str == '>' || *str == ',' || *str == '.' || *str == '/')
		return (1);
	if (*str == '?' || *str == '~' || *str == '`')
		return (1);
	return (0);
}

void	clear_pipe(int *fd)
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}
