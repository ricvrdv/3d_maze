/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:02:05 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:57:22 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>

int   main(void)
{
        char    *source = "world!";
        char    destination[] = "Hello ";
        size_t  total_length;
        size_t  size;

        printf("Destination: \"%s\"\tSource: \"%s\"\n", destination, source);
        size = 10;
        total_length = ft_strlcat(destination, source, size);
	printf("Concatenated (length = %zu): \"%s\"\n", total_length, destination);
        if (size <= total_length)
                printf("The resulting string was truncated.\n");
        return (0);
}*/
