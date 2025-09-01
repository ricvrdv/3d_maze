/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:14:16 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:35:35 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

/*
#include <stdio.h>
#include <fcntl.h>

int   main(void)
{
        int     fd = 1;
        int     test_nbr = -425;
        char    buffer[20] = {0};
        ssize_t bytes_read;

        printf("TESTING FOR STDOUT (fd = 1):\n");
        ft_putnbr_fd(test_nbr, fd);
        printf("\n\n");

        fd = open("test_output_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
                perror("Error opening file");
                return (1);
        }
        printf("TESTING FOR FILE OUTPUT:\n");
        ft_putnbr_fd(test_nbr, fd);
        close(fd);
        fd = open("test_output_putnbr.txt", O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file for reading");
                return (1);
        }
        bytes_read = read(fd, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0)
        {
                buffer[bytes_read] = '\0';
                printf("Number written to file: %s\n", buffer);
        }
        close(fd);

        return (0);
}*/
