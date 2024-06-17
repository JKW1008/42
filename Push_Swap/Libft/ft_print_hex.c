/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:36:50 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 18:06:18 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_ft_puthex_fd(unsigned long long pointer, \
int *count, const char *str)
{
	unsigned int		i;
	unsigned long long	t;

	if (pointer > 0)
	{
		i = pointer % 16;
		t = pointer / 16;
		print_ft_puthex_fd(t, count, str);
		write(1, &str[i], 1);
		(*count)++;
	}
}

void	print_ft_putpointer_fd(unsigned long long pointer, int *count)
{
	const char			*str;

	str = "0123456789abcdef";
	if (pointer == 0)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	print_ft_puthex_fd(pointer, count, str);
}

void	print_ft_putunsignedint_fd(unsigned int n, int *count)
{
	if (n >= 10)
	{
		print_ft_putunsignedint_fd(n / 10, count);
		print_ft_putunsignedint_fd(n % 10, count);
	}
	else
		print_ft_putchar_fd(n + '0', count);
}

void	print_lowerx(unsigned int lowercase, int *count)
{
	const char	*str;

	str = "0123456789abcdef";
	if (lowercase == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	print_ft_puthex_fd((unsigned long long)lowercase, count, str);
}

void	print_upperx(unsigned int uppercase, int *count)
{
	const char	*str;

	str = "0123456789ABCDEF";
	if (uppercase == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	print_ft_puthex_fd((unsigned long long)uppercase, count, str);
}
