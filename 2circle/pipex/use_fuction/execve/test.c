#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *args[], char **envp)
{
	char **argv;
	argv = (char **)malloc(sizeof(char *) * 5);
	argv[0] = "ls";
	argv[1] = "-al";
	argv[2] = "/";
	argv[3] = NULL;
	execve("/usr/bin/ls", argv, envp);
}
