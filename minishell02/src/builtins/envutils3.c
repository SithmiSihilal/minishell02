/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envutils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:00:45 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/01/11 14:20:30 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sync_my_env(t_core *core)
{
	if (core->my_env)
		freeenvcpy(core->my_env);
	core->my_env = getenvcpy(core);
}
