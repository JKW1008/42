/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:57:00 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 20:30:31 by kjung            ###   ########.fr       */
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
void	exec(char *cmd, char **envp);
void	here_doc(char **argv);
void	do_pipe(char *cmd, t_pbdata *data, pid_t *pids, int *p_fd);
void	here_doc_put_in(char **argv, int *p_fd);

//  px_utils_bonus.c
int		open_file(char *file, int in_or_out);
void	dodo(t_pbdata *data);
void	after_dodo(int out_fd, t_pbdata *data);
int		check_here_doc(char **av, int ac, int *out, int *in);

//	px_utils2_bonus.c
void	initdata(t_pbdata *data, char **argv, char **envp, int i);
void	initdata2(t_pbdata *data, pid_t *pid, int *out, int ac);

#endif