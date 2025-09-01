/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:02:53 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:29:36 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static char	test_tolower(unsigned int i, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\0')
		len++;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		string[i] = (*f)(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*static char	test_tolower(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

#include <stdio.h>

int     main(void)
{
        char    *string = "HELLO World";
        char    *new_string;

        printf("Original string:\n\"%s\"\tAddress: %p\n", string, string);
        new_string = ft_strmapi(string, test_tolower);
        printf("New string:\n\"%s\"\tAddress: %p\n", new_string, new_string);
        free(new_string);

        return (0);
}*/
