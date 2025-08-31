/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:18:44 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:47:17 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	int	c1;
	int	c2;
	
	if (argc == 2)
	{
		c1 = ft_isalpha(argv[1][0]);
		c2 = isalpha(argv[1][0]);
		printf("Using ft_isalpha\n");
		if (c1)
			printf("%c is an alphabetic character.\n\n", argv[1][0]);
		else
			printf("%c is not an alphabetic character.\n\n", argv[1][0]);
		printf("Using isalpha\n");
		if (c2)
			printf("%c is an alphabetic character.\n", argv[1][0]);
		else
			printf("%c is not an alphabetic character.\n", argv[1][0]);
		return (0);
	}
	return (1);
}*/
