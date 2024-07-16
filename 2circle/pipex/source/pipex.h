/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:26:49 by kjung             #+#    #+#             */
/*   Updated: 2024/07/16 17:42:57 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X_H
# define PIPE_X_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <wait.h>

char	*find_path(char **envp, char *str);

#endif
