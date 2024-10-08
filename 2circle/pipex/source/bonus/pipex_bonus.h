/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:57:00 by kjung             #+#    #+#             */
/*   Updated: 2024/07/25 21:45:35 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pbdata
{
	char	**envp;
	char	**argv;
	int		argc;
	int		i;
	int		index;
	int		*out;
	pid_t	*pid;
}	t_pbdata;

//	pipex_bonus.c
void	exec(char *cmd, char **env);
void	do_pipe(char *cmd, char **env, int *p_fd, int is_last);
void	setup_here_doc(int ac, char **av, char **env);
void	setup_pipes_and_execute(int ac, char **av, char **env);

//	px_do_bonus.c
void	do_work3(char *cmd, char **env, pid_t *pid, int *p_fd);
void	do_pipe2(int *p_fd, int is_last);
void	do_pipe3(int *p_fd, int is_last);
void	do_pipe(char *cmd, char **env, int *p_fd, int is_last);

//  px_utils_bonus.c
int		open_file(char *file, int in_or_out);
int		ft_strcmp(const char *str1, const char *str2);
void	here_doc_put_in(char **av, int *p_fd);
void	here_doc(char **av);
void	check_cmd(char *cmd, char **env);

#endif