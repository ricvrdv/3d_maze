/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:47 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:32:16 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
}

/*
#include <stdio.h>
#include <fcntl.h>

int   main(void)
{
        int     fd = 1;
        char    *test_str = "Bye bye";
        char    buffer[10] = {0};

        printf("TESTING FOR STDOUT (fd = 1)\n");
        ft_putstr_fd(test_str, fd);
        printf("\n\n");

        fd = open("test_output_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
                perror("Error opening file");
                return (1);
        }
        printf("TESTING FOR FILE OUTPUT\n");
        ft_putstr_fd(test_str, fd);
        close(fd);
        fd = open("test_output_putstr.txt", O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file for reading");
                return (1);
        }
        read(fd, buffer, 7);
        printf("String written to file: %s\n", buffer);
        close(fd);

        return (0);
}*/
