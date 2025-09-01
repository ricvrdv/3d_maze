/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: applecore <applecore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:10:28 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/12 20:47:05 by applecore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*sjoint;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	sjoint = (char *)gnl_calloc((gnl_strlen(s1) + gnl_strlen(s2) + 1), 1);
	if (!sjoint)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sjoint[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sjoint[i + j] = s2[j];
		j++;
	}
	sjoint[i + j] = '\0';
	return (sjoint);
}

char	*gnl_substr(char *s, size_t start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
		return (gnl_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)gnl_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*buffer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	buffer = (unsigned char *)malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}
