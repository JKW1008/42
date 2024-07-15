#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 5

int main()
{
	char buf[BUFF_SIZE];
	int fd;
	ssize_t rd_size;
	
	if ((fd = open("test.txt", O_RDONLY)) > 0)
	{
		while (0 < (rd_size = read(fd, buf, BUFF_SIZE - 1)))
		{
			buf[rd_size] = '\0';
			puts(buf);
		}
		close(fd);
	}
	else
	{
		printf("there's no file");
	}
	return 0;
}
