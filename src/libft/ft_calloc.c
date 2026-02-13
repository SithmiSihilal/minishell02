/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:01:34 by siellage          #+#    #+#             */
/*   Updated: 2024/11/26 14:25:03 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = malloc (nmemb * size);
	if (!temp)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		temp[i++] = 0;
	}
	return (temp);
}
/*int main() {
    int *arr = ft_calloc(5, sizeof(int));
    if (!arr) return 1;  // Memory allocation failed
    for (int i = 0; i < 5; i++) printf("arr[%d] = %d\n", i, arr[i]);
    free(arr);
    return 0;
}*/
