/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:45:45 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:53:09 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	uc;
	char			*ptr;
	size_t			i;

	ptr = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer_1[] = "Hello";
	char	buffer_2[] = "Hello";

	printf("Original buffer_1: \"%s\"\n", buffer_1);
	
	ft_memset(buffer_1, 'a', 3);
	printf("After ft_memset(): \"%s\"\n\n", buffer_1);
	
	printf("Original buffer_2: \"%s\"\n", buffer_2);
	memset(buffer_2, 'a', 3);
	printf("After memset(): \"%s\"\n", buffer_2);
	return (0);
}*/
