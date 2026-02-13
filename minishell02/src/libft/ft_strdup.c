/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:31:48 by siellage          #+#    #+#             */
/*   Updated: 2024/11/26 16:37:16 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (temp == NULL)
	{
		return (NULL);
	}
	ft_strlcpy (temp, s, ft_strlen(s) + 1);
	return (temp);
}
/*int main(void)
{
    char *string = ft_strdup("Hello :)");
    if (string)
    {
        printf("Original: Hello :)\nDuplicate: %s\n", string);
        free(string);
    }
    return 0;
}*/
