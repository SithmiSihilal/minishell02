/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:19:25 by siellage          #+#    #+#             */
/*   Updated: 2024/12/02 10:19:46 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_word(char const *s, char c)
{
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	len;
	int		i;

	string = (char **)malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!s || !string)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			string[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	string[i] = NULL;
	return (string);
}
/*int main(void)
{
    char **result = ft_split("Hello,,world,,this,is,C programming", ',');
    
    for (int i = 0; result[i]; i++) {
        printf("[%s]\n", result[i]);
        free(result[i]); 
    }
    
    free(result);
    return 0;
}*/
