/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:18:23 by siellage          #+#    #+#             */
/*   Updated: 2024/11/19 15:28:48 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*#include <stdio.h>
int main()
{
    const char *str = "Hello, World!";
    size_t length = ft_strlen(str);
    printf("The length of the string \"%s\" is: %zu\n", str, length);

    return 0;
}*/
