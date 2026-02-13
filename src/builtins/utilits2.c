/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:10:06 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:28:44 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_len(char *str)
{
	if (!str)
		return (0);
	return (ft_strlen(str));
}

void	ownstrjoin(char **dst, char *src)
{
	char	*ptr;
	char	*hp;
	char	*hd;
	size_t	len;

	if (!*dst && !src)
		return ;
	len = get_len(*dst) + get_len(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return ;
	ptr[len] = 0;
	hp = ptr;
	hd = *dst;
	while (hd && *hd)
		*(hp++) = *(hd++);
	while (src && *src)
		*(hp++) = *(src++);
	if (*dst)
		free(*dst);
	*dst = ptr;
}

void	straddchar(char **dst, char c)
{
	char	*ptr;
	char	*hp;
	char	*hd;
	int		len;

	len = ft_strlen(*dst) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return ;
	hp = ptr;
	hd = *dst;
	while (hd && *hd)
		*(hp++) = *(hd++);
	*(hp++) = c;
	*(hp++) = 0;
	if (*dst)
		free(*dst);
	*dst = ptr;
}
