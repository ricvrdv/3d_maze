/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:10:11 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:00:40 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	ch = (char)c;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int   main(void)
{
        char    *string = "ornitorrinco";
        char    to_locate = 'i';
        char    *location_1 = ft_strrchr(string, to_locate);
        char    *location_2 = strrchr(string, to_locate);

        printf("String: \"%s\"\tTo locate: \"%c\"\n", string, to_locate);
        printf("Last occurrence (using ft_strrchr): %s\n", location_1);
        printf("Last occurrence (using strrchr):    %s\n", location_2);
        return (0);
}*/
