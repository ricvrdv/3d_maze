/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:17:11 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:03:33 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				i;

	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int   main(void)
{
        char    *mem_1 = "abcdefg";
        char    *mem_2 = "abxdefg";
        size_t  n = sizeof(char) * 4;
        int     result_1 = ft_memcmp(mem_1, mem_2, n);
        int     result_2 = memcmp(mem_1, mem_2, n);

        printf("Memory area 1: %s\nMemory area 2: %s\n", mem_1, mem_2);
        printf("Result (using ft_memcmp) = %d\n", result_1);
        printf("Result (using memcmp)    = %d\n", result_2);
        return (0);
}*/
