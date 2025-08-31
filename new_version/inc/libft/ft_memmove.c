/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:56:03 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/01/21 14:21:05 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;
	size_t				i;

	if (!src && !dest)
		return (NULL);
	ptr_src = (const unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	if (ptr_dest == ptr_src)
		return (dest);
	i = n;
	if (ptr_dest > ptr_src)
	{
		while (i > 0)
		{
			ptr_dest[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(ptr_dest, ptr_src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int   main(void)
{
        char    buffer_src_1[] = "Hello world!";
        char    buffer_src_2[] = "Hello world!";
        char    buffer_src_3[] = "Hello world!";
        char    buffer_src_4[] = "Hello world!";

        printf("------------------------------------------\nNO OVERLAPPING\n");
        printf("Source 1:\n\"%s\"\n", buffer_src_1);
        ft_memmove(buffer_src_1, buffer_src_1 + 6, 5);
        printf("Destination 1 after (ft_memcpy()):\n\"%s\"\n\n", buffer_src_1);
        printf("Source 2:\n\"%s\"\n", buffer_src_2);
        memmove(buffer_src_2, buffer_src_2 + 6, 5);
        printf("Destination 2 after (memcpy()):\n\"%s\"\n\n", buffer_src_2);

        printf("------------------------------------------\nOVERLAPPING\n");
        printf("Source 1:\n\"%s\"\n", buffer_src_3);
        ft_memmove(buffer_src_3 + 3, buffer_src_3, 5);
        printf("Destination 1 after (ft_memcpy()):\n\"%s\"\n\n", buffer_src_3);
        printf("Source 2:\n\"%s\"\n", buffer_src_4);
        memmove(buffer_src_4 + 3, buffer_src_4, 5);
        printf("Destination 2 after (memcpy()):\n\"%s\"\n", buffer_src_4);

        return (0);
}*/
