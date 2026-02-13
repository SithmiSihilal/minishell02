/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:51:12 by siellage          #+#    #+#             */
/*   Updated: 2024/11/23 10:51:53 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
/*#include <stdio.h>
#include <bsd/string.h>
int main() {
    char dst[20] = "Hello, ";
    const char *src = "World!";
    size_t size = sizeof(dst);

    // Display before and after applying ft_strlcat
    printf("Before ft_strlcat: %s\n", dst);
    ft_strlcat(dst, src, size);
    printf("After ft_strlcat: %s\n", dst);

    return 0;
}*/
