#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int counter = 1;
    int status;
    pid_t pid;
    pid_t pid_child;

    printf("부모 : 첫 번째 자식 프로세스를 생성합니다.\n");
    pid = fork();

    switch (pid)
    {
    case -1:
        printf("자식 프로세스 생성 실패\n");
        return -1;
    case 0:
        printf("1st: 저는 첫번째 자식 프로세스로 5까지 카운트하고 종료하겠습니다.\n");
        while (6 > counter)
        {
            printf("1st : %d\n", counter++);
            sleep(1);
        }
        return 99;
    default:
        printf("부모 : 두 번째 자식 프로세스를 생성합니다.\n");
        pid = fork();

        switch (pid)
        {
        case -1:
            printf("자식 프로세스 생성 실패.\n");
            return -1;
        case 0:
            printf("2nd : 저는 두 번째 자식 프로세스로 10까지 카운트하고 종료하겠습니다.\n");
            while (11 > counter)        
            {
                printf("2nd : %d\n", counter++);
                sleep(1);
            }
            return 99;
        default:
            printf("부모 :  저는 부모 프로세스로 자식 프로세스 \
작업이 끝날 때 까지 대기합니다..\n");

            pid_child = waitpid(pid, &status, 0);

            printf("부모 : 종료된 자식 프로세스 ID는 %d이며,", pid_child);
            if ((status & 0xff) == 0)
                printf("정상적으로 종료되었고 반환값은 %d입니다.\n", status >> 8);
            else
                printf("비 정상으로 종료되었고 종료 시그널 번호는 %d입니다.\n", status);
            printf("이제 제 일을 처리하겠습니다.\n");
            while (1)
            {
                printf("부모 : %d\n", counter++);
                sleep(1);
            }
        }
    }
}