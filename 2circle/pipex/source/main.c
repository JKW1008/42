/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:14:02 by kjung             #+#    #+#             */
/*   Updated: 2024/07/16 18:42:00 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **envp, char *cmd, int fd, char *argv, int *pipe)
{
	char	**divided;
	divided = ft_split(argv, ' ');
	close(pipe[0]);
	dup2(fd, 0);
	dup2(pipe[1], 1);
	close(fd);
	close(pipe[1]);
	execve(cmd, divided, envp);
}

void	parent_process(char **envp, char *cmd, int fd, char *argv, int *pipe)
{
	char **divided;
	divided = ft_split(argv, ' ');
	close(pipe[1]);
	dup2(fd, 1);
	dup2(pipe[0], 0);
	close(fd);
	close(pipe[0]);
	execve(cmd, divided, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file_dis[2];
	char	*cmd;
	char	*cmd2;
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error");
			exit(1);
		}
		cmd = find_path(envp, argv[2]);
		cmd2 = find_path(envp, argv[3]);
		file_dis[0] = open(argv[1], O_RDONLY);
		pid = fork();

		printf("%d\n", pid);
		if (pid == -1)
			printf("자식 프로세스 생성 실패\n");
		else if (pid == 0)
		{
			printf("fuck suck\n");
			child_process(envp, cmd, file_dis[0], argv[2], fd);
		}
		else if (pid > 0)
		{
			pid = fork();
			parent_process(envp, cmd2, file_dis[1], argv[3], fd);
		}
		// execve
	}
	// path = /bin/ls 
	// argv "ls" => ["ls", NULL]
	//  infile < ls | wc -l > outfile
	// 1. infile, outfile fd를 저장
	// 2. 자식 생성 (fork후 dup2로 파일 디스크팁터 변경)
	// 3. execve() 실행 => -1 이면 에러일때 따로 처리 exit()
	// 4. wait으로 자식 프로세스 감시
}