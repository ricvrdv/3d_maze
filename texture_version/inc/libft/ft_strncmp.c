/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:12:15 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:01:40 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char)s1[i] != (unsigned char)s2[i])
			|| (unsigned char)s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int   main(int argc, char *argv[])
{
        int     result_1;
        int     result_2;

        if (argc == 4)
        {
                printf("s1: \"%s\"\ts2: \"%s\"\n", argv[1], argv[2]);
                result_1 = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
                printf("Result (using ft_strncmp) = %d\n", result_1);

                result_2 = strncmp(argv[1], argv[2], atoi(argv[3]));
                printf("Result    (using strncmp) = %d\n", result_2);
                return (0);
        }
        return (1);
}*/
