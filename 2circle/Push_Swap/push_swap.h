/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:44:20 by kjung             #+#    #+#             */
/*   Updated: 2024/06/21 14:41:33 by kjung            ###   ########.fr       */
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
	int				rank;
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	int				size;
	struct s_lst	*head;
	struct s_lst	*tail;
}	t_stack;

//	main.c
int			main(int argc, char *argv[]);

//	ps_arr_utils.c
void		free_split(char **line);

// ps_check_arg.c
int			check_arguments_for_char(t_stack *stack, char *argv);
int			check_arguments_for_digit(t_stack *stack, char **argv);
int			check_sorted(t_stack *stack);
int			check_arg(int argc, char **argv, t_stack *stack);

//	ps_lst_parcing.c
void		parcing_list_for_char(t_stack *stack, char **devided);
void		parcing_list_for_digit(t_stack *stack, char **argv);

//	ps_lst_utils.c
void		free_list(t_stack *stack);
t_lst		*ft_ps_lstlast(t_lst *lst);
void		ft_lstadd_ps_back(t_stack *stack, t_lst *ne);
int			check_list_for_duplication(t_stack *stack);

//	ps_stack_utils.c
void		init_stack(t_stack *stack);
void		update_rank(t_stack *stack);

//	ps_utils.c
long long	ft_atol(const char *str);

#endif
