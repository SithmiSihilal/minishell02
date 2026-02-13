/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:07:47 by siellage          #+#    #+#             */
/*   Updated: 2024/11/19 13:09:48 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*int main() {
    for (int i = 31; i <= 128; i++) {
        printf("Character '%c' is %sprintable.\n", i, 
		ft_isprint(i) ? "" : "not ");
    }
    return 0;
}*/
