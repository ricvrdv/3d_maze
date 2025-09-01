/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:25:17 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:48:25 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
		c1 = ft_isdigit(argv[1][0]);
		c2 = isdigit(argv[1][0]);
		printf("Using ft_isdigit\n");
		if (c1)
			printf("%c is a digit.\n\n", argv[1][0]);
		else
			printf("%c is not a digit.\n\n", argv[1][0]);
		printf("Using isdigit\n");
		if (c2)
			printf("%c is a digit.\n", argv[1][0]);
		else
			printf("%c is not a digit.\n", argv[1][0]);
		return (0);
	}
	return (1);
}*/
