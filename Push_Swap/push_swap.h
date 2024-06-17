/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:44:20 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 16:13:27 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>

//	ps_arr_utils.c
void		free_split(char **line);

//	ps_utils.c
long long	ft_atol(const char *str);

// ps_check_arg.c
int			check_arguments_for_char(char *argv);
int			check_arguments_for_digit(char **argv);
int			check_arg(int argc, char **argv);


#endif
