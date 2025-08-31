/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:36 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:31:44 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

/*
#include <stdio.h>
#include <fcntl.h>

int   main(void)
{
        int     fd = 1;
        char    test_char = 'R';
        char    buffer[2] = {0};

        printf("TESTING FOR STDOUT (fd = 1):\n");
        ft_putchar_fd(test_char, fd);
        printf("\n\n");

        fd = open("test_output_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
                perror("Error opening file");
                return (1);
        }
        printf("TESTING FOR FILE OUTPUT:\n");
        ft_putchar_fd(test_char, fd);
        close(fd);
        fd = open("test_output_putchar.txt", O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file for reading");
                return (1);
        }
        read(fd, buffer, 1);
        printf("Character written to file: %c\n", buffer[0]);
        close(fd);
        return (0);
}*/
