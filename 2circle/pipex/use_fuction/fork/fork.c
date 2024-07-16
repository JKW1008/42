#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int counter = 0;
    pid_t pid;

    printf("자식 프로세스 생성");
    pid = fork();

    switch (pid)
    {
    case -1:
        printf("자식 프로세스 생성 실패\n");
        break;
    case 0:
        printf("저는 자식 프로세스로 디스카운트 하겠습니다.\n");
        while (1)
        {
            printf("자식 : %d\n", counter--);
            sleep(1);
        }
    default:
        printf("저는 부모 프로세스로 카운트 하겠습니다.\n");
        printf("자식 프로세스의 pid는 %d입니다\n", pid);
        for (int i = 0; i < 10; i++)
        {
            printf("부모 : %d\n", counter++);
            sleep(1);
        }
        exit(0);
        break;
    }
    return 0;
}