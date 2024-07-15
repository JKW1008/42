#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *tmp = "hello, world";
	int fd;
	
	if (0 < (fd = open("test.txt", O_WRONLY | O_CREAT | O_EXCL, 0644)))
	{
		write(fd, tmp, strlen(tmp));
		close(fd);
	}
	else
	{
		printf("theres no file\n");
	}
	return 0;
}
