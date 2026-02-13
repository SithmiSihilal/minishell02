/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:02:52 by siellage          #+#    #+#             */
/*   Updated: 2024/11/23 12:03:15 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char) c)
	{
		return ((char *) s);
	}
	return (NULL);
}
/*int main()
{
    const char *str = "Hello, world!";
    printf("Found '%c' at: %ld\n", 'o', ft_strchr(str, 'o') - str);
    printf("Found NULL terminator at: %ld\n", ft_strchr(str, '\0') - str);
    return 0;
}*/
