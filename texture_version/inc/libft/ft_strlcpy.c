/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:59:49 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:56:41 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>

int   main(void)
{
        char    *source = "Hello world!";
        char    destination[10];
        size_t  length;

        length = ft_strlcpy(destination, source, 10);
        printf("Source (length = %zu): \"%s\"\n", length, source);
        printf("Destination: \"%s\"\n", destination);
        return (0);
}*/
