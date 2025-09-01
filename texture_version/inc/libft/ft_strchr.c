/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:07:57 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:59:45 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int   main(void)
{
        char    string[] = "ornitorrinco";
        char    to_locate = 't';
        char    *location_1 = ft_strchr(string, to_locate);
        char    *location_2 = strchr(string, to_locate);

        printf("String: \"%s\"\tTo locate: \"%c\"\n", string, to_locate);
        printf("First occurrence (using ft_strchr): %s\n", location_1);
        printf("First occurrence (using strchr):    %s\n", location_2);
        return (0);
}*/
