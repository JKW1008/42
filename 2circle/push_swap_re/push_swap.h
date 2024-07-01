/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:12:15 by kjung             #+#    #+#             */
/*   Updated: 2024/07/01 19:38:35 by kjung            ###   ########.fr       */
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
	int				a_cost;
	int				b_cost;
	char			b_or_t;
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
void		two_input_sort(t_stack *stack_a);

//	ps_a_to_b.c
void		min_a_sort(t_stack *stack_a);
void		a_to_b(t_stack *stack_a, t_stack *stack_b, t_plst *p_lst);

//	ps_arg_check.c
int			check_arg_char_while(char **div);
int			check_arguments_for_char(t_stack *stack, char *argv);
int			check_arguments_for_digit(t_stack *stack, char **argv);
int			check_arg(int argc, char **argv, t_stack *stack);
int			check_all(int argc, char *argv[], t_stack *stack);

//	ps_b_to_a.c
void		rc_node_go_a(t_stack *stack_a, t_stack *stack_b);
void		rc_node_go_head(t_stack *stack_a, t_stack *stack_b, t_lst *node);
void		find_rc_node(t_stack *stack_a, t_stack *stack_b);
void		b_to_a(t_stack *stack_a, t_stack *stack_b);

//	ps_cal_cost.c
void		input_b_cost(t_lst *node, int t_count, int b_count);
void		cal_b_cost(t_lst *node);
void		cal_a_cost(t_lst *node, t_stack *stack_a);
void		cal_cost(t_stack *stack_a, t_stack *stack_b);

//	ps_find_node.c
int			find_lower(t_stack *stack_a, t_stack *stack_b);
int			find_bigger(t_stack *stack_a, t_stack *stack_b);

//	ps_go_a_utils.c
void		go_a_util(t_stack *stack_a, t_stack *stack_b);
void		go_a_util2(t_stack *stack_a, t_stack *stack_b);
void		go_a_util3(t_stack *stack_a, t_stack *stack_b);

//	ps_list_utils.c
void		free_split(char **line);
void		init_pivot(t_plst *p_lst);
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
