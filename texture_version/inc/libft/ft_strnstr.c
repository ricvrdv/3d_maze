/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:19:41 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:04:30 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	little_len = 0;
	while (little[little_len] != '\0')
		little_len++;
	while (big[i] != '\0' && i < len)
	{
		if (len - i < little_len)
			return (NULL);
		j = 0;
		while (big[i + j] == little[j] && j < little_len && i + j < len)
			j++;
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int   main(int argc, char *argv[])
{
        char    *big = argv[1];
        char    *little = argv[2];
        size_t  len = atoi(argv[3]);

        if (argc == 4)
        {
		printf("Big: \"%s\"\tLittle: \"%s\"\tlength = %zu\n", big, little, len);
                printf("First instance: \"%s\"\n", ft_strnstr(big, little, len));
                return (0);
        }
        return (1);
}*/
