/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: applecore <applecore@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:02:44 by rjesus-d          #+#    #+#             */
/*   Updated: 2025/03/12 20:47:51 by applecore        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_file(int fd, char **saved);
static char		*extract_and_update_line(char **saved);

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
	{
		saved = gnl_strdup("");
		if (!saved)
			return (NULL);
	}
	while (!gnl_strchr(saved, '\n'))
	{
		bytes_read = read_file(fd, &saved);
		if (bytes_read < 0)
			return (free_and_reset(&saved), NULL);
		if (bytes_read == 0 && saved && *saved)
			return (line = saved, saved = NULL, line);
		if (bytes_read == 0 && (!saved || !*saved))
			return (free_and_reset(&saved), NULL);
	}
	line = extract_and_update_line(&saved);
	return (line);
}

static ssize_t	read_file(int fd, char **saved)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free_and_reset(&buffer), bytes_read);
	buffer[bytes_read] = '\0';
	temp = gnl_strjoin(*saved, buffer);
	free_and_reset(&buffer);
	if (!temp)
		return (*saved = NULL, -1);
	free_and_reset(saved);
	*saved = temp;
	return (bytes_read);
}

static char	*extract_and_update_line(char **saved)
{
	char	*new_line;
	char	*line;
	char	*temp;
	size_t	len;

	new_line = gnl_strchr(*saved, '\n');
	if (new_line)
	{
		len = new_line - *saved + 1;
		line = gnl_substr(*saved, 0, len);
		if (!line)
			return (free_and_reset(saved), NULL);
		temp = gnl_substr(*saved, len, gnl_strlen(*saved) - len);
		if (!temp)
			return (free_and_reset(saved), free_and_reset(&line), NULL);
		free_and_reset(saved);
		*saved = temp;
	}
	else
	{
		line = *saved;
		*saved = NULL;
	}
	return (line);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	char	*buffer;

	if (!s)
		return (NULL);
	buffer = (char *)gnl_calloc((gnl_strlen(s) + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	free_and_reset(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}
