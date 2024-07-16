#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFF_SIZE 1024

int main()
{
    int pipes_parent[2];
    int pipes_child[2];
    char buff[BUFF_SIZE];
    int counter = 0;
    pid_t pid;

    if (pipe(pipes_parent) == -1)
    {
        perror("파이프 생성 실패");
        exit(1);
    }
    if (pipe(pipes_child) == -1)
    {
        perror("파이프 생성 실패");
        exit(1);
    }
    pid = fork();

    switch (pid)
    {
    case -1:
        printf("자식 프로세스 생성 실패\n");
        return -1;
    case 0:
        while (1)
        {
            sprintf(buff, "자식 메시지 : %d", counter++);
            write(pipes_child[1], buff, strlen(buff));
            memset(buff, 0, BUFF_SIZE);
            read(pipes_parent[0], buff, BUFF_SIZE);
            printf("자식 프로세스 : %s\n", buff);
            sleep(1);
        }
    default:
        while (1)
        {
            sprintf(buff, "부모 메시지 : %d", counter--);
            write(pipes_parent[1], buff, strlen(buff));
            memset(buff, 0, BUFF_SIZE);
            read(pipes_child[0], buff, BUFF_SIZE);
            printf("부모 프로세스 : %s\n", buff);
            sleep(1);
        }
        break;
    }
}