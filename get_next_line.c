/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:09:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/07/16 16:56:11 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_from_buffer(char **buffer)
{
	char	*newline_pos;
	char	*line;
	char	*rest;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
		rest = ft_strdup(newline_pos + 1);
		free(*buffer);
		*buffer = rest;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static int	read_into_buffer(int fd, char **buffer)
{
	char	*temp_buffer;
	char	*read_buffer;
	ssize_t	bytes_read;

	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(read_buffer);
		return (bytes_read);
	}
	read_buffer[bytes_read] = '\0';
	temp_buffer = ft_strjoin(*buffer, read_buffer);
	free(*buffer);
	free(read_buffer);
	*buffer = temp_buffer;
	return (bytes_read);
}

static int	read_until_newline(int fd, char **buffer)
{
	int	bytes_read;

	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_read = read_into_buffer(fd, buffer);
		if (bytes_read == 0)
			return (0);
		if (bytes_read < 0)
		{
			free(*buffer);
			*buffer = NULL;
			return (-1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buffer)
		buffer = ft_strdup("");
	if (read_until_newline(fd, &buffer) < 0)
		return (0);
	if (*buffer)
		line = get_line_from_buffer(&buffer);
	else
	{
		free(buffer);
		buffer = NULL;
		line = NULL;
	}
	return (line);
}
