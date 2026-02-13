/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:07:19 by siellage          #+#    #+#             */
/*   Updated: 2024/11/27 12:12:19 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}
/*int main()
{
	int fd;
    ft_putstr_fd("Hello :)\n", 1); //output to standard output
	fd = open("example.text", O_WRONLY | O_CREAT);
	//O_WRONLY  write permissions 
	//O_CREAT  creates the file if it doesn't exist
	close(fd); // close file descripter
    return 0;
}*/
