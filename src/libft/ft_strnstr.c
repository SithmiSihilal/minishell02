/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:36:31 by siellage          #+#    #+#             */
/*   Updated: 2024/11/26 10:24:37 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *) big);
	}
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little [j] && (i + j) < len)
		{
			j++;
			if (little [j] == '\0')
			{
				return ((char *) big + i);
			}
		}
		i++;
	}
	return (NULL);
}
/*int main() 
{
    const char *big = "Hello, World!";
    const char *little = "World";
    size_t len = 12;

    char *result = ft_strnstr(big, little, len);
    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}*/
