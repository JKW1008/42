#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main()
{
    int fd_wr;
    int fd_rd;
    char buff[BUFF_SIZE];
    char *str = "hello, world";

    fd_wr = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    fd_rd = dup2(fd_wr, 100);
    printf("fd_wr = %d, fd_rd = %d\n", fd_wr, fd_rd);

    write(fd_wr, str, strlen(str));
    close(fd_wr);

    lseek(fd_rd, 0, SEEK_SET);
    memset(buff, '\0', BUFF_SIZE);
    read(fd_rd, buff, BUFF_SIZE);

    printf("%s\n", buff);

    close(fd_rd);

    return 0;
}