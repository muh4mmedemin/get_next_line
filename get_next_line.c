/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:21:11 by muayna            #+#    #+#             */
/*   Updated: 2025/08/02 15:24:47 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*read_to_n(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*remainder = NULL;
	char		*line = ft_strdup(remainder ? remainder : "");
	int			read_size = 1;
	char		*newline_pos;

	free(remainder);
	remainder = NULL;
	while (!(newline_pos = ft_strchr(line, '\n')) && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(line);
			return NULL;
		}
		buf[read_size] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (newline_pos)
	{
		remainder = ft_strdup(newline_pos + 1);
		*(newline_pos + 1) = '\0';
	}
	return line;
}

char	*read_line(char *str)
{
	if (!str || !str[0])
	{
		free(str);
		return NULL;
	}
	return str;
}

char	*get_next_line(int fd)
{
	if (fd < 0)
		return NULL;
	char	*s = read_to_n(fd);
	if (!s)
		return NULL;
	char	*t = read_line(s);
	return t;
}
