/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:35:36 by siellage          #+#    #+#             */
/*   Updated: 2024/11/21 13:58:55 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ddest;
	char	*ssrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	ddest = (char *)dest;
	ssrc = (char *)src;
	i = -1;
	if (ddest > ssrc)
	{
		while (n > 0)
		{
			--n;
			ddest[n] = ssrc[n];
		}
	}
	else
	{
		while (++i < n)
		{
			ddest[i] = ssrc[i];
		}
	}
	return (dest);
}
/*int main()
{
    char src[] = "Hello, World!";
    char dest[20];
    ft_memmove(dest, src, strlen(src) + 1); // +1 for null terminator
    printf("Destination after memmove: %s\n", dest);
    return 0;

}*/
