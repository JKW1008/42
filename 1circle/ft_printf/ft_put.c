/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:30:56 by kjung             #+#    #+#             */
/*   Updated: 2024/04/22 17:23:45 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int *count)
{
	if (!s)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (*s)
	{
		write(1, s, 1);
		(*count)++;
		s++;
	}
}

void	ft_putchar_fd(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr_fd(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', count);
		ft_putnbr_fd(n *= -1, count);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, count);
		ft_putnbr_fd(n % 10, count);
	}
	else
		ft_putchar_fd(n + '0', count);
}
