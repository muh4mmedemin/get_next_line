/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:21:11 by muayna            #+#    #+#             */
/*   Updated: 2025/08/02 05:04:03 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *read_line(char *str)
{
    int i;
    int destsize;
    char *line;

    destsize = 0;
    i = 0;
    destsize = ft_strlen(str);
    line = malloc(destsize + 1);
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        //printf("LİNE %s LİNE", line);
        i++; 
    }
    line[i] = '\n';
    line[i + 1] = '\0';
    return line;
}

char *read_to_n(int fd)
{
    char *line;
    char buf[BUFFER_SIZE + 1];
    static char *temp;
    int read_size = 1;
    line = ft_strdup("");
    if(temp)
    {
        line = ft_strjoin(line, temp);
    }
    while ((ft_strchr(line, '\n') || ft_strchr(line, '\0')) && read_size != 0)
    {
        read_size = read(fd, buf, BUFFER_SIZE);
        buf[read_size] = '\0';
        line = ft_strjoin(line, (char *)buf);
        if (ft_strchr(line, '\n'))
            temp = ft_strchr(line, '\n');
        else if (read_size == 0)
            return line;
    }
    if (read_size == -1)
        return (NULL);
    return (line);
}

char *get_next_line(int fd)
{
    return read_line(read_to_n(fd));
}
// line = 1234567890
// line static char !!
// str = 123456789
// line 123456789\n
// new_line 897897
// free(line)
// return (line)
// return (str)

int main ()
{
    int fd = open("string.txt", O_RDWR, 0777);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    close(fd);
}