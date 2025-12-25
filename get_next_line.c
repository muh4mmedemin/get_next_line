/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:43:47 by muayna            #+#    #+#             */
/*   Updated: 2025/12/25 18:08:57 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	int		i;
	int		b;
	char	*newstr;
	int		totalstr;

	b = 0;
	i = 0;
	totalstr = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = malloc(totalstr + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		newstr[i] = s2[b];
		b++;
		i++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

static void	save_after_n(char *line, char *temp)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = ft_strchr(line, '\n');
	new_line++;
	while (new_line[i])
	{
		temp[i] = new_line[i];
		i++;
	}
	temp[i] = '\0';
}

static char	*create_line(char *line)
{
	char	*new_line;
	int		line_size;
	int		i;

	line_size = 0;
	i = 0;
	while (line[line_size] != '\n')
		line_size++;
	new_line = malloc(line_size + 2);
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[line_size] = '\n';
	new_line[line_size + 1] = '\0';
	free(line);
	return (new_line);
}

static char	*read_file(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	int		read_size;

	line = ft_strdup("");
	read_size = 1;
	if (temp[0] != '\0')
	{
		line = ft_strjoin_free_s1(line, temp);
		temp[0] = '\0';
	}
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		line = ft_strjoin_free_s1(line, buf);
		if (read_size < BUFFER_SIZE)
			return (line);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, temp);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n'))
	{
		save_after_n(line, temp);
		line = create_line(line);
	}
	return (line);
}
