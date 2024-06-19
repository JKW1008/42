#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char a[10];
    int fd;
    int i;

    if (0 < (fd = open("./test.txt", O_RDONLY)))
    {
        i = read(fd, a, 5);
        a[i] = '\0';
        printf("%s %d\n",a, i); //12345 5
        i = read(fd, a, 2);
        a[i] = '\0';
        printf("%s %d\n",a, i);//67 2
        i = read(fd, a, 10);
        a[i] = '\0';
        printf("%s %d\n",a, i);// 89 2
        i = read(fd, a, 5);
        a[i] = '\0';
        printf("%s %d\n",a, i);// 0
        i = read(fd, a, 5);
        a[i] = '\0';
        printf("%s %d\n",a, i);// 0
        close(fd);
    } else {
        printf("나락");
    }
    return 0;
}