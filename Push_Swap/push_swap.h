/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:44:20 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 19:15:40 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_lst
{
	int				index;
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

//	main.c
int			main(int argc, char *argv[]);

//	ps_arr_utils.c
void		free_split(char **line);

// ps_check_arg.c
int			check_arguments_for_char(t_lst **a_list, char *argv);
int			check_arguments_for_digit(char **argv);
int			check_arg(int argc, char **argv, t_lst **list_a);

//	ps_lst_parcing.c
void		parcing_list_for_char(t_lst **list_a, char **devided);

//	ps_lst_utils.c
void		ft_ps_lstadd_front(t_lst **lst, t_lst *new);
t_lst		*ft_ps_lstlast(t_lst *lst);
void		ft_lstadd_ps_back(t_lst **lst, t_lst *ne);

//	ps_utils.c
long long	ft_atol(const char *str);

#endif
