/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:41 by siellage          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:50 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(int number)
{
	int	len;

	len = 0;
	if (number <= 0)
		len = 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*string;

	num = n;
	len = ft_number(n);
	string = (char *) malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	if (num < 0)
	{
		string[0] = '-';
		num = -num;
	}
	string[len] = '\0';
	while (num > 0)
	{
		string[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		string[0] = '0';
	return (string);
}
/*int main()
{
    int num1 = 12345;
    char *result1 = ft_itoa(num1);
    printf("Result 1: %s\n", result1);
    free(result1);
    return 0;
}*/
