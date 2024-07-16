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

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file_dis[2];
	char	*cmd;
	pid_t	pid;
	
	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error");
			exit(1);
		}
		cmd = find_path(envp, argv[2]);
		printf("%s\n", cmd);
		file_dis[0] = open(argv[1], O_RDONLY);

		pid = fork();
		
		if (pid == -1)
			printf("자식 프로세스 생성 실패\n");
		dup2(file_dis[0], 0);
		
		execve
	}
	// path = /bin/ls 
	// argv "ls" => ["ls", NULL]
	//  infile < ls | wc -l > outfile
	// 1. infile, outfile fd를 저장
	// 2. 자식 생성 (fork후 dup2로 파일 디스크팁터 변경)
	// 3. execve() 실행 => -1 이면 에러일때 따로 처리 exit()
	// 4. wait으로 자식 프로세스 감시
}