#include "get_next_line.h"
#include <stdio.h>

int main ()
{
    char buf[BUFFER_SIZE];
    int fd = open("a.txt", O_RDWR, 0777);
    read(fd, buf, BUFFER_SIZE);
    printf("%s", buf);
}