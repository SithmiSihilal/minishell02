/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:23:58 by siellage          #+#    #+#             */
/*   Updated: 2024/11/27 10:28:50 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		ft_putnbr_fd (n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
		else
		{
			digit = n + 48;
			write (fd, &digit, 1);
		}
	}
}
/*int main(void)
{
    int fd;
    ft_putnbr_fd(42, 1);//output to standard output
    fd = open("example.text", O_WRONLY | O_CREAT);
	//O_WRONLY  write permissions 
	//O_CREAT  creates the file if it doesn't exist
	close(fd); // close file descripter
    return 0;
}*/
