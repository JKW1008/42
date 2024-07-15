#include <stdio.h>

#define MAX_BUF_SIZE 128

int main()
{
	FILE *fd;
	char buffer[MAX_BUF_SIZE] = {0,};
	char *ret;

	fd = fopen("not_exitst.txt", "r");
	if (fd != NULL)
		fclose(fd);
	else
	{	
		ret = fgets(buffer, MAX_BUF_SIZE, NULL);
		if (ret == NULL)
			perror("fgets error");
	}
	return 0;
}
