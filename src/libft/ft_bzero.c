/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:49:18 by siellage          #+#    #+#             */
/*   Updated: 2024/11/20 12:10:15 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *) s;
	while (n > i)
	{
		tmp[i++] = 0;
	}
}
/*#include <stdio.h>
int main() {
    char str[] = "Hello, world!";
    
    printf("Before ft_bzero: %s\n", str);
    ft_bzero(str, 5);

    printf("After ft_bzero: %s\n", str);

    return 0;
}*/
