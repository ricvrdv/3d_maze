/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:47:02 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/01/21 12:29:15 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c);
static char	**fill_array(char *s, char **str_array, char c);
static char	*extract_word(char *s, char c);
static void	free_all(char **result, int count);

char	**ft_split(char *s, char c)
{
	char	**str_array;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	if (!word_count)
		return (NULL);
	str_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!str_array)
		return (NULL);
	return (fill_array(s, str_array, c));
}

static int	count_words(char *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	**fill_array(char *s, char **str_array, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			str_array[i] = extract_word(s, c);
			if (!str_array[i])
			{
				free_all(str_array, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	str_array[i] = NULL;
	return (str_array);
}

static char	*extract_word(char *s, char c)
{
	const char	*end;
	char		*word;
	int			len;
	int			i;

	end = s;
	while (*end && *end != c)
		end++;
	len = end - s;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

/*
#include <stdio.h>

int   main(void)
{
        char    *string = "Oops I dit it again!";
        char    delimiter = ' ';
        char    **str_array;
        char    **original_ptr;

        printf("Original string: \"%s\"\n", string);
        str_array = ft_split(string, delimiter);
        original_ptr = str_array;
        printf("Split strings:\n{\n");
        while (*str_array != 0)
        {
                printf("\"%s\"\n", *str_array);
                str_array++;
        }
        printf("}\n");
        free_all(original_ptr, count_words(string, delimiter));

        return (0);
}*/
