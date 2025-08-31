/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:40:59 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:26:05 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(const char *set, char c);
static char	*trimming(const char *s1, size_t start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]) && j > i)
		j--;
	if (j >= i)
		len = j - i + 1;
	else
		len = 0;
	return (trimming(s1, i, len));
}

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*trimming(const char *s1, size_t start, size_t len)
{
	char	*trimmed;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	trimmed = malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}

/*
#include <stdio.h>

int   main(void)
{
        char    *s = "   \tHello Please Trim me!\n ";
        char    *set = " \n\t";
        char    *s_trimmed;

        printf("Original string:\n\"%s\"\n", s);
        printf("Set: {%s}\n", set);
        s_trimmed = ft_strtrim(s, set);
        printf("Trimmed string:\n\"%s\"\n", s_trimmed);
        return (0);
}*/
