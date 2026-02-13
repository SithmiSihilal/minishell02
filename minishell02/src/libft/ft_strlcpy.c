/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:44:50 by siellage          #+#    #+#             */
/*   Updated: 2024/11/23 10:45:22 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			i++;
		}
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*int main() {
    char dest[20];
    const char *src = "Hello, World!";
    size_t size = sizeof(dest);

    // Copy string using ft_strlcpy
    size_t result = ft_strlcpy(dest, src, size);

    // Print the destination string and the result
    printf("Copied string: %s\n", dest);
    printf("Total length of source: %zu\n", result);

    return 0;
}*/
