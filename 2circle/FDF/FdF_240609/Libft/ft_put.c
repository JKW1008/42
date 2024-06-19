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

#include "libft.h"

void	print_ft_putstr_fd(char *s, int *count)
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

void	print_ft_putchar_fd(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	print_ft_putnbr_fd(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (n < 0)
	{
		print_ft_putnbr_fd('-', count);
		print_ft_putnbr_fd(n *= -1, count);
	}
	else if (n >= 10)
	{
		print_ft_putnbr_fd(n / 10, count);
		print_ft_putnbr_fd(n % 10, count);
	}
	else
		print_ft_putchar_fd(n + '0', count);
}
