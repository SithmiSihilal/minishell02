/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:33:32 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/01/30 15:49:22 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	int		len;
// 	int		i;

// 	if (!s)
// 		return (NULL);
// 	len = ft_strlen(s);
// 	ptr = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = s[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

// Mock: prints which built-in was detected
int	exec_builtin(char **args)
{
	if (!args || !args[0])
		return (1);
	if (ft_strcmp(args[0], "echo") == 0)
	{
		printf("[MOCK] Built-in echo detected\n");
		return (0);
	}
	if (ft_strcmp(args[0], "env") == 0)
	{
		printf("[MOCK] Built-in env detected\n");
		return (0);
	}
	return (1);
}

void	print_env(char **my_env)
{
	int	i;

	i = 0;
	while (my_env[i])
	{
		printf("%s\n", my_env[i]);
		i++;
	}
}

void	free_resources(char *input, char **parts, char *original)
{
	if (parts)
		free_env(parts);
	if (original)
		free(original);
	if (input)
		free(input);
}
