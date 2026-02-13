/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:34:17 by siellage          #+#    #+#             */
/*   Updated: 2024/11/25 16:18:10 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		target;
	size_t				i;

	i = 0;
	str = (unsigned char *) s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == target)
		{
			return ((void *) & str[i]);
		}
		i++;
	}
	return (NULL);
}
/*int main() {
    const char data[] = "Hello, world!";
    char target = 'o';
    size_t n = 13;  
    void *result = memchr(data, target, n);

    if (result != NULL) {
        printf("Found '%c' at position: %ld\n", 
        target, (long)((char *)result - data));
    } else {
        printf("Character '%c' not found.\n", target);
    }

    return 0;
}*/
