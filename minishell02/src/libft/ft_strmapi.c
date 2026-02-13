/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:38:26 by siellage          #+#    #+#             */
/*   Updated: 2025/10/31 17:32:14 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	i = 0;
	string = (char *)malloc(ft_strlen(s) + 1);
	if (!s || !f)
		return (0);
	if (!string)
		return (0);
	while (s[i])
	{
		string[i] = f(i, (char)s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
/*char example(unsigned int i, char c) {
    return c - i;  
}

int main(void) {
    char *result = ft_strmapi("hello world", example);
    printf("%s\n", result);
    free(result);
    return 0;
}*/
