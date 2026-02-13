/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:34:12 by siellage          #+#    #+#             */
/*   Updated: 2024/11/27 14:47:50 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
/*int main() {
   int fd;
    ft_putendl_fd("Hello :)\n", 1); //output to standard output
	fd = open("example.text", O_WRONLY | O_CREAT);
	//O_WRONLY  write permissions 
	//O_CREAT  creates the file if it doesn't exist
	close(fd); // close file descripter
    return 0;
}*/
