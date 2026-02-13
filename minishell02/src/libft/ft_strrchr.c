/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:41 by siellage          #+#    #+#             */
/*   Updated: 2024/11/25 14:25:47 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*lastocc;

	lastocc = NULL;
	while (*s)
	{
		if (*s == (char) c)
		{
			lastocc = (char *) s;
		}
		s++;
	}
	if (*s == (char) c)
	{
		return ((char *) s);
	}
	return (lastocc);
}
/*int main() {
    const char *str = "Hello,world!";
    char c = '\0';

    char *result = strrchr(str, c);

    if (result != NULL) {
        printf("Last occurrence of '%c' found at position: 
        %ld\n", c, result - str);
    } else {
        printf("Character '%c' not found.\n", c);
    }

    return 0;
}*/
