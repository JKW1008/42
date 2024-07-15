#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
        printf("환경변수 %s는 %s\n", argv[1], getenv(argv[1]));
    else
        printf("실행방법 : show_envp [환경변수]\n");
    return 0;
}