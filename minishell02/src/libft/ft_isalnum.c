/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:34:14 by siellage          #+#    #+#             */
/*   Updated: 2024/11/19 12:47:14 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}
/*int main() 
{
    char str = 'A';

    if (ft_isalnum(str)) 
    {
        printf("'%c' is alphanumeric.\n", str);
    } else 
    {
        printf("'%c' is not alphanumeric.\n", str);
    }
}*/
