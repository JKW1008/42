/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:12:15 by kjung             #+#    #+#             */
/*   Updated: 2024/06/28 23:41:36 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_lst
{
	int				index;
	int				rank;
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_plst
{
	int	l_pivot;
	int	h_pivot;
}	t_plst;

typedef struct s_stack
{
	int				size;
	int				input_size;
	struct s_lst	*head;
	struct s_lst	*tail;
}	t_stack;

//	main.c
int			main(int argc, char *argv[]);

//	ps_a_to_b.c
void		min_a_sort(t_stack *stack_a);
void		a_to_b(t_stack *stack_a, t_stack *stack_b);

//	ps_arg_check.c
int			check_arg_char_while(char **div);
int			check_arguments_for_char(t_stack *stack, char *argv);
int			check_arguments_for_digit(t_stack *stack, char **argv);
int			check_arg(int argc, char **argv, t_stack *stack);
int			check_all(int argc, char *argv[], t_stack *stack);

//	ps_list_utils.c
void		free_split(char **line);
void		parcing_list_for_char(t_stack *stack, char **devided);
void		parcing_list_for_digit(t_stack *stack, char **argv);

//	ps_list_utils2.c
void		free_list(t_stack *stack);
t_lst		*ft_ps_lstlast(t_lst *lst);
void		ft_lstadd_ps_back(t_stack *stack, t_lst *new);

//	ps_push.c
void		push(t_stack *dst, t_stack *src);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_b, t_stack *stack_a);

//	ps_r_rotate.c
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

//	ps_rotate.c
void		rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

//	ps_stack_check.c
int			check_list_for_duplication(t_stack *stack);
int			check_sorted(t_stack *stack);

//	ps_stack_utils.c
void		init_stack(t_stack *stack);
void		update_rank(t_stack *stack);
void		call_stack_free(t_stack *stack_a, t_stack *stack_b);

//	ps_str_utils.c
long long	ft_atol(const char *str);

//	ps_swap.c
void		swap(t_stack *stack);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);

#endif
