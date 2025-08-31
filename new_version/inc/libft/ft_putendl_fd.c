/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:27 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:33:14 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	write(fd, "\n", sizeof(char));
}

/*
#include <stdio.h>
#include <fcntl.h>

int   main(void)
{
        int     fd = 1;
        char    *test_string = "Get me a line";
        char    buffer[20];

        printf("TESTING FOR STDOUT (fd = 1)\n");
        ft_putendl_fd(test_string, fd);

        fd = open("test_output_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
                perror("Error opening file");
                return (1);
        }
        printf("TESTING FOR FILE OUTPUT\n");
        ft_putendl_fd(test_string, fd);
        close(fd);
        fd = open("test_output_putendl.txt", O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file for reading");
                return (1);
        }
        read(fd, buffer, 14);
write(fd, "\n", sizeof(char));  printf("String written to file: %s\n", buffer);
        close(fd);

        return (0);
}*/
