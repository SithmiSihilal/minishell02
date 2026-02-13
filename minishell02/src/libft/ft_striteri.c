/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:28:30 by siellage          #+#    #+#             */
/*   Updated: 2024/12/02 10:28:49 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*void example_function(unsigned int index, char *c) 
{
    *c += index;
}

int main(void) 
{
    char str[] = "abcdef";
    ft_striteri(str, example_function);
    printf("Modified string: %s\n", str);
    return 0;
}*/
