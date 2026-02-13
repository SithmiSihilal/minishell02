/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:40:00 by siellage          #+#    #+#             */
/*   Updated: 2024/11/20 13:47:05 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ddest;
	char		*ssrc;

	ddest = (char *)dest;
	ssrc = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		ddest[n -1] = ssrc[n -1];
		n--;
	}
	return (dest);
}
/*int main() {
    char src[] = "Hello, world!";
    char dest[20]; 

    ft_memcpy(dest, src, 13);  

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}*/
