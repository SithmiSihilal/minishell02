/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:05:53 by siellage          #+#    #+#             */
/*   Updated: 2024/11/19 12:16:24 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	while ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*int main()
{
    char c = '5';
    if (ft_isdigit(c))
    printf("%c is a digit\n", c);
    else
    printf("%c is not a digit\n", c);
    return 0;
}*/
