/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:26:49 by kjung             #+#    #+#             */
/*   Updated: 2024/07/25 22:44:41 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	char	**envp;
	char	**argv;
	pid_t	*pid;
}	t_data;

//	pipex.c
void	child_process(t_data *str, int *pipe);
void	parent_process(t_data *str, int *pipe);
void	do_work2(t_data *str, int *pipe_fd, pid_t *pid);
void	do_work(t_data	*str, int *pipe_fd);

//	px_utils.c
void	init_struct(t_data *str, char **argv, char **evnp, pid_t *pid);
void	free_split(char **str);
char	*check_access(char *split, char *str);
char	*fp_while(char **split, char *str);
char	*find_path(char **envp, char *str);
char	*check_absolute_or_home_path(char *str);

//	px_error.c
void	px_error(char *argv);

#endif