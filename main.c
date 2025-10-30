#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("vacio.txt", O_RDONLY);
    char    *line;
    if(fd <0)
        return(1);
    line = get_next_line(fd);
    while ((line = get_next_line(fd))!= NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return(0);
}