#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void save_after_n(char *str, char **temp)
{
    *temp = ft_strchr(str, '\n');
}

char *read_line(char *str)
{
    int i;
    int destsize;
    char *line;

    destsize = 0;
    i = 0;
    destsize = ft_strlen(str);
    line = malloc(destsize + 2);
    while (str[i] != '\n')
    {
        line[i] = str[i];
        i++; 
    }
    line[i] = '\n';
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
    while ((find_n((line) , '\n') != 1) && read_size != 0)
    {
        read_size = read(fd, buf, BUFFER_SIZE);
        line = ft_strjoin(line, (char *)buf);
        if (ft_strchr(line, '\n'))
        {
            temp = ft_strchr(line, '\n');
        }
        else if (read_size == 0)
        {
            printf("sa");
            return line;
        }
    }
    printf("\nTEMP %s\n", temp);
    return (line);
}

char *get_next_line(int fd)
{
    char *s = read_to_n(fd);
    return read_line(s);
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
    printf("ÇIKTI%s", get_next_line(fd));
    printf("ÇIKTI%s", get_next_line(fd));
    printf("ÇIKTI%s", get_next_line(fd));
}