/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:33:10 by siellage          #+#    #+#             */
/*   Updated: 2025/11/17 11:27:26 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isvalidnflag(char *str)
{
	int	i;

	if (!str || str[0] != '-')
		return (0);
	i = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	runecho(t_cmdlist *cmdnode)
{
	char	**path;
	int		isn;

	isn = 0;
	path = &cmdnode->path[1];
	while (*path && isvalidnflag(*path))
	{
		isn = 1;
		path++;
	}
	while (*path)
	{
		if (*path)
			write(cmdnode->outfile, *path, ft_strlen(*path));
		if (*(++path))
			write(cmdnode->outfile, " ", 1);
	}
	if (!isn)
		write(cmdnode->outfile, "\n", 1);
}
