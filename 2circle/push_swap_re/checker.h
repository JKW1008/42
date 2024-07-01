/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:04:29 by kjung             #+#    #+#             */
/*   Updated: 2024/07/01 21:01:00 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "push_swap.h"

int			ft_strcmp(const char *str1, const char *str2);
void		do_op_r_rr(char *str, t_stack *stack_a, t_stack *stack_b);
void		do_op_ps(char *str, t_stack *stack_a, t_stack *stack_b);
void		input_operator(t_stack *stack_a, t_stack *stack_b);

#endif