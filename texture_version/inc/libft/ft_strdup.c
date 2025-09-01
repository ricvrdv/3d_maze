/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:31:25 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:23:03 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	len = 0;
	while (s[len] != '\0')
		len++;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/*
#include <stdio.h>
#include <string.h>

int   main(void)
{
        char    *to_copy = "here we go again";
        char    *copied_1;
        char    *copied_2;

        printf("Original: \"%s\"\t", to_copy);
        printf("Memory address: %p\n\n", &to_copy);

        copied_1 = ft_strdup(to_copy);
        printf("Using ft_strdup:\nNew:      \"%s\"\t", copied_1);
        printf("Memory address: %p\n", &copied_1);
        free(copied_1);

        copied_2 = strdup(to_copy);
        printf("Using strdup:\nNew:      \"%s\"\t", copied_2);
        printf("Memory address: %p\n", &copied_2);
        free(copied_2);

        return (0);
}*/
