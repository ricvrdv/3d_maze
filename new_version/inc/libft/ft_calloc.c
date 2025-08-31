/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:28:12 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:21:11 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	buffer = (void *)malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}

/*
#include <stdio.h>

int   main(void)
{
        size_t  nmemb = 10;
        size_t  size = 4;
        size_t  i = 0;
        char    *buffer_1;
        char    *buffer_2;

        printf("%zu elements\t%zu bytes each\n", nmemb, size);

        buffer_1 = (char *)ft_calloc(nmemb, size);
        printf("Using ft_calloc(): [");
        while (i < nmemb)
        {
                printf("%d", buffer_1[i]);
                i++;
        }
        printf("]\n");
        free(buffer_1);

        buffer_2 = (char *)calloc(nmemb, size);
        printf("Using calloc():    [");
        i = 0;
        while (i < nmemb)
        {
                printf("%d", buffer_2[i]);
                i++;
        }
        printf("]\n");
        free(buffer_2);

        return (0);
}*/
