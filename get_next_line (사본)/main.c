#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("hello.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("file open fail");
        return (1);
    }
	while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            printf("FILE END\n");
            return 0;
        }
        printf("%s", line);
        free(line);
        line = 0;
    }
    close(fd);
    return (0);
}