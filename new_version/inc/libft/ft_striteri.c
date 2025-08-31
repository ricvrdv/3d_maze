/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:06:51 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:30:28 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	test_tolower(unsigned int i, char *c);

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
static void	test_tolower(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

#include <stdio.h>

int     main(void)
{
        char    string[] = "HELLO World";

        printf("String:\n\"%s\"\tAddress: %p\n", string, string);
        ft_striteri(string, test_tolower);
        printf("Modified string:\n\"%s\"\tAddress: %p\n", string, string);
        return (0);
}*/
