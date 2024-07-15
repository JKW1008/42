#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // for open
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char *filename = "test.txt";
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		fprintf(stderr, "%s open error\n", filename);
		exit(1);
	}

	printf("Descriptor : %d\n", fd);
	close(fd);
	
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		fprintf(stderr, "%s open error\n", filename);
		exit(1);
	}

	printf("Descriptor : %d\n", fd);
	exit(0);
}
