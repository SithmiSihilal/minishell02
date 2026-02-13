/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:39:11 by siellage          #+#    #+#             */
/*   Updated: 2024/11/20 10:20:52 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*tmp;
	size_t				i;

	i = 0;
	tmp = (unsigned char *) s;
	while (n > i)
	{
		tmp[i++] = (unsigned char) c;
	}
	return (s);
}
/*#include <stdio.h>
int main()
{
    char str[] = "Hello, World!";
    printf("Before ft_memset: %s\n", str);
    ft_memset(str, 'X', 5);
    printf("After ft_memset: %s\n", str);
    char str2[] = "Hello, World!";
    ft_memset(str2, 'X', 5);
    printf("After standard memset: %s\n", str2);

    return 0;
}*/
