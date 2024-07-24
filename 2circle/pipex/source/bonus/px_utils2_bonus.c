/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:28:57 by kjung             #+#    #+#             */
/*   Updated: 2024/07/24 19:30:26 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../pipex.h"

void	initdata(t_pbdata *data, char **argv, char **envp, int i)
{
	data->argv = argv;
	data->envp = envp;
	data->i = i;
}

void	initdata2(t_pbdata *data, pid_t *pid, int *out, int ac)
{
	data->pid = pid;
	data->out = out;
	data->argc = ac;
}
