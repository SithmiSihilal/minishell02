/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:57:11 by siellage          #+#    #+#             */
/*   Updated: 2024/11/27 15:01:46 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*int main() 
{
	int fd;
	ft_putchar_fd('S', 1);//outout the character
	fd = open("example.txt", O_WRONLY | O_CREAT); 
	//O_WRONLY  write permissions 
	//O_CREAT  creates the file if it doesn't exist
	close(fd); // close file descripter
	return 0;
}*/
