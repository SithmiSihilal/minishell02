/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:16:46 by siellage          #+#    #+#             */
/*   Updated: 2024/11/19 11:31:15 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
/*int main() {
    char str = 'A'; 

    if (ft_isalpha(str)) {
        printf("%c is an alphabetic\n", str);
    } else {
        printf("%c is not an alphabetic\n", str);
    }

    return 0;
}*/
