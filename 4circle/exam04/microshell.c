#include <stdio.h>       // 표준 입출력 함수 사용
#include <stdlib.h>      // 메모리 할당, 프로세스 제어 함수 사용
#include <string.h>      // 문자열 처리 함수 사용
#include <unistd.h>      // POSIX 운영체제 API 사용
#include <sys/wait.h>    // 자식 프로세스 대기 함수 사용

#define STDIN_FILENO 0   // 표준 입력 파일 디스크립터
#define STDOUT_FILENO 1  // 표준 출력 파일 디스크립터
#define STDERR_FILENO 2  // 표준 오류 파일 디스크립터

// 오류 메시지 상수 정의
#define ERR_CD_BAD "error: cd: bad arguments"
#define ERR_CD_DIR "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal"
#define ERR_EXE "error: cannot execute "

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])      // 문자열 끝(널 문자)까지 반복
        i++;
    return (i);         // 문자열 길이 반환
}

void ft_putstr(char *err, char *arg)
{
    write(2, err, ft_strlen(err));           // 오류 메시지를 표준 오류(stderr)에 출력
    if (arg)
        write(2, arg, ft_strlen(arg));       // 인자가 있으면 인자도 출력
    write(2, "\n", 1);                       // 줄바꿈 출력
}

int find_end_point(int i, char **av)
{
    int ep;
    ep = 0;
    while (av[i + ep] && strcmp(av[i + ep], ";") && strcmp(av[i + ep], "|"))
        ep++;           // 현재 위치에서 ';'나 '|'를 만날 때까지 인자 수 카운트
    return ep;          // 현재 명령어의 인자 수 반환
}

void	cd_command(int idx, int ep, char **av)
{
    if (ep != 2)        // 'cd' 명령과 디렉토리 경로로 정확히 2개의 인자가 필요
    {
        ft_putstr(ERR_CD_BAD, NULL);
        return;
    }
    if (chdir(av[idx + 1]) == -1)    // 디렉토리 변경 시도
    {
        ft_putstr(ERR_CD_DIR, av[idx + 1]);    // 실패하면 오류 메시지 출력
    }
}

void	command_exe(int	prev_fd, int ep, char **av, char **env)
{
    if (prev_fd != STDIN_FILENO)   // 이전 파이프에서 입력을 받는 경우
    {
        dup2(prev_fd, STDIN_FILENO);    // 이전 파이프의 출력을 현재 프로세스의 표준 입력으로 연결
        close(prev_fd);                 // 원본 파일 디스크립터 닫기
    }
    av[ep] = NULL;                      // 명령어 인자 배열의 끝을 NULL로 표시
    if (execve(av[0], av, env) == -1)   // 명령어 실행
    {
        ft_putstr(ERR_EXE, av[0]);      // 실행 실패 시 오류 메시지 출력
        exit(1);                         // 자식 프로세스 종료
    }
}

int main(int ac, char **av, char **env)
{
    int     idx;        // 현재 처리 중인 인자 인덱스
    int     ep;         // 현재 명령어의 인자 수
    int     fd[2];      // 파이프 파일 디스크립터 배열
    int     prev_fd;    // 이전 파이프의 읽기 끝 파일 디스크립터
    pid_t   pid;        // 프로세스 ID
    
    idx = 1;            // 첫 번째 인자부터 시작 (프로그램 이름 건너뜀)
    prev_fd = STDIN_FILENO;  // 초기에는 표준 입력에서 읽음
    
    while (idx < ac)    // 모든 인자를 처리할 때까지 반복
    {
        ep = findEndPoint(idx, av);  // 현재 명령어의 인자 수 찾기
        
        if (ep == 0)    // 빈 명령어(예: 연속된 세미콜론)인 경우 건너뜀
        {
            idx++;
            continue;
        }
        
        if (strcmp(av[idx], "cd") == 0)  // 'cd' 내장 명령어 처리
        {
            customCD(idx, ep, av);
            idx += ep + 1;  // 다음 명령어로 이동
            continue;
        }
        
        // 다음 인자가 없거나 세미콜론인 경우 (파이프 없음)
        if (!av[idx + ep] || !strcmp(av[idx + ep], ";"))
        {
            pid = fork();  // 자식 프로세스 생성
            
            if (pid == -1)  // fork 실패
            {
                ft_putstr(ERR_FATAL, NULL);
                exit(1);
            }
            else if (pid == 0)  // 자식 프로세스
            {
                customExecve(prev_fd, ep, &av[idx], env);  // 명령어 실행
            }
            else  // 부모 프로세스
            {
                if (prev_fd != STDIN_FILENO)
                {
                    dup2(prev_fd, STDIN_FILENO);  // 이전 파이프의 출력을 표준 입력으로 연결
                    close(prev_fd);               // 원본 파일 디스크립터 닫기
                }
                prev_fd = 0;  // 파이프 리셋
                while (waitpid(-1, NULL, WUNTRACED) > 1);  // 모든 자식 프로세스 종료 대기
            }
        }
        else  // 다음 인자가 파이프인 경우
        {
            pipe(fd);  // 새 파이프 생성
            pid = fork();  // 자식 프로세스 생성
            
            if (pid == -1)  // fork 실패
            {
                ft_putstr(ERR_FATAL, NULL);
                exit(1);
            }
            else if (pid == 0)  // 자식 프로세스
            {
                dup2(fd[0], STDIN_FILENO);  // 파이프의 읽기 끝을 표준 입력으로 연결
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);  // 파이프의 쓰기 끝을 표준 출력으로 연결
                close(fd[1]);
                customExecve(prev_fd, ep, &av[idx], env);  // 명령어 실행
            }
            else  // 부모 프로세스
            {
                close(fd[1]);  // 파이프의 쓰기 끝 닫기 (읽기만 필요)
                if (prev_fd != STDIN_FILENO)
                {
                    dup2(prev_fd, STDIN_FILENO);  // 이전 파이프의 출력을 표준 입력으로 연결
                    close(prev_fd);
                }
                prev_fd = fd[0];  // 현재 파이프의 읽기 끝을 다음 명령어를 위해 저장
                while (waitpid(-1, NULL, WUNTRACED) > 1);  // 모든 자식 프로세스 종료 대기
            }
        }
        
        idx += ep + 1;  // 다음 명령어로 이동
    }
    
    close(prev_fd);  // 마지막 파이프 닫기
}
