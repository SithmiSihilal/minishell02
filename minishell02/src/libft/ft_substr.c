/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:36:01 by siellage          #+#    #+#             */
/*   Updated: 2024/11/28 14:00:03 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	size_t	i;
	char	*string;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sublen = ft_strlen(s) - start;
	if (sublen > len)
		sublen = len;
	string = (char *)malloc((sublen + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
/*int main()
{
    unsigned char *substr;
	
	substr = ft_substr("", 0, 0);
	if (substr)
	{
    	printf("%s\n", substr);
    		free(substr);
	}
	else
		printf ("NULL\n");
    return 0;
}*/
