#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (0 != getuid())
    {
        printf("슈퍼유저만 사용할 수 있습니다.\n");
        exit(-1);
    }
    printf("이것은 exit() 샘플입니다.\n");

    return 0;
}