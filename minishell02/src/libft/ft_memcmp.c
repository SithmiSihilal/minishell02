/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:05:50 by siellage          #+#    #+#             */
/*   Updated: 2024/11/25 17:29:19 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*string1;
	const unsigned char		*string2;
	size_t					i;

	i = 0;
	string1 = (const unsigned char *) s1;
	string2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
		i++;
	}
	return (0);
}
/*int main()
 {
    const char *str1 = "hello";
    const char *str2 = "hello";
    const char *str3 = "world";

    // Compare str1 and str2 (should be equal)
    printf("memcmp(str1, str2, 5) = %d\n", memcmp(str1, str2, 5));

    // Compare str1 and str3 (should be different)
    printf("memcmp(str1, str3, 5) = %d\n", memcmp(str1, str3, 5));

    return 0;
}*/
