/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 00:13:04 by muayna            #+#    #+#             */
/*   Updated: 2025/08/10 00:19:37 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_after_n(char *line, char **t)
{
	char	*n;
	int		i;

	i = 0;
	n = ft_strchr(line, '\n');
	n++;
	while (n[i])
		i++;
	*t = malloc(i + 1);
	i = 0;
	while (n[i])
	{
		(*t)[i] = n[i];
		i++;
	}
	(*t)[i] = '\0';
}

char	*extract_line(char *line)
{
	char	*new_line;
	int		count_line;
	int		i;

	count_line = 0;
	i = 0;
	while (line[count_line] != '\n')
		count_line++;
	new_line = malloc(count_line + 2);
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\n';
	new_line[i + 1] = '\0';
	return (new_line);
}

char	*read_file(int fd, char **temp)
{
	char	*buf;
	char	*line;
	int		read_size;

	read_size = 1;
	line = ft_strdup("");
	if (*temp)
	{
		line = ft_strjoin(line, *temp);
		free(*temp);
		*temp = NULL;
	}
	buf = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n') || read_size < BUFFER_SIZE)
		{
			free(buf);
			return (line);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*old_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, &temp);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n'))
	{
		find_after_n(line, &temp);
		old_line = line;
		line = extract_line(line);
		free(old_line);
	}
	return (line);
}
