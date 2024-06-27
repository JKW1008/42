/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:44:20 by kjung             #+#    #+#             */
/*   Updated: 2024/06/27 20:58:31 by kjung            ###   ########.fr       */
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
	int				a_cost;
	int				b_cost;
	char			b_or_t;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	int				size;
	int				input_size;
	struct s_lst	*head;
	struct s_lst	*tail;
}	t_stack;

typedef struct s_pivot
{
	int		lowest_pivot;
	int		middle_pivot;
	int		highest_pivot;
}	t_pivot;

typedef struct s_recovery
{
	int	ra_cost;
	int	rb_cost;
	int rr_cost;
	int	rra_cost;
	int rrb_cost;
}	t_recovery;


//	main.c
void		print_stack(t_stack *stack);
int			main(int argc, char *argv[]);

//	ps_arr_utils.c
void		free_split(char **line);

//	ps_cal_cost.c
void		top_or_bottom(t_lst *node);
void		input_cost(t_lst *node, int t_count, int b_count);
void		move_a_cost(t_lst *node, t_stack *stack_a);

// ps_check_arg.c
int			check_arguments_for_char(t_stack *stack, char *argv);
int			check_arguments_for_digit(t_stack *stack, char **argv);
int			check_sorted(t_stack *stack);
int			check_arg(int argc, char **argv, t_stack *stack);

//	ps_cost_check.c
void		min_a_sort(t_stack *stack_a);
void		move_b_a_be_min(t_stack *stack_a, t_stack *stack_b);
void		move_b(t_stack *stack_a, t_stack *stack_b);

//	ps_lst_parcing.c
void		parcing_list_for_char(t_stack *stack, char **devided);
void		parcing_list_for_digit(t_stack *stack, char **argv);

//	ps_lst_utils.c
void		free_list(t_stack *stack);
t_lst		*ft_ps_lstlast(t_lst *lst);
void		ft_lstadd_ps_back(t_stack *stack, t_lst *ne);
int			check_list_for_duplication(t_stack *stack);

//	ps_operator.c
void		push(t_stack *dst, t_stack *src);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

//	ps_sort.c
void		cal_input_size(t_stack *stack);
void		init_in_stack_move(t_stack *stack_b, t_stack *stack_a);
void		sort_push_for_a(t_stack *stack_a, t_stack *stack_b, t_pivot *pivot);
void		real_sort_for_a(t_stack *stack_a, t_stack *stack_b, int pivot);
// void		ra_for_cost(t_stack *stack_a, int cost);
// void		recovery_sort(t_stack *stack_a, int cost);


//	ps_stack_utils.c
void		init_stack(t_stack *stack);
void		update_rank(t_stack *stack);
int			value_in_stack(int start, int end, t_stack *stack);

//	ps_utils.c
long long	ft_atol(const char *str);

//	ps_write_operator(p, rr, r, s).c
//		push
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_b, t_stack *stack_a);

//		r_rotate
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

//		rotate
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

//		swap
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);

#endif
