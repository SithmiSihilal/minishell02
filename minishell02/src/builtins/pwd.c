/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:34:06 by siellage          #+#    #+#             */
/*   Updated: 2025/11/17 11:28:33 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	runpwd(t_cmdlist *cmdnode)
{
	char	cwd[256];
	char	*pwd;

	pwd = getcwd(cwd, 256);
	write(cmdnode->outfile, pwd, ft_strlen(pwd));
	write(cmdnode->outfile, "\n", 1);
}
