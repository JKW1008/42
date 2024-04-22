/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:04:21 by kjung             #+#    #+#             */
/*   Updated: 2024/04/20 18:36:33 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *ptr, ...);
void	check_type(const char *c, va_list ap, int *count);
void	ft_puthex_fd(unsigned long long pointer, int *count, const char *str);
void	ft_putpointer_fd(unsigned long long pointer, int *count);
void	ft_putunsignedint_fd(unsigned int n, int *count);
void	print_lowerx(unsigned int lowercase, int *count);
void	print_upperx(unsigned int uppercase, int *count);
void	ft_putstr_fd(char *s, int *count);
void	ft_putchar_fd(char c, int *count);
void	ft_putnbr_fd(int n, int *count);

#endif
