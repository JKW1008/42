#include "../source/pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	pipe(fd);
	int pc = fork();
	if (pc == 0)
	{
		// printf("Hello I'm child!\n");
		// while(1)
		// {}
		execve("./test", NULL, "/home/kjung/Desktop/42/2circle/pipex/test");
	}
	else
	{
		printf("Hello I'm papa mama!\n");
		while(1)
		{}
	}
	return (0);
}