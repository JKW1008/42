/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:19:33 by kjung             #+#    #+#             */
/*   Updated: 2024/04/20 18:29:13 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_check_type(const char *c, va_list ap, int *count)
{
	if (*c == 's')
		print_ft_putstr_fd(va_arg(ap, char *), count);
	else if (*c == 'c')
		print_ft_putchar_fd(va_arg(ap, int), count);
	else if (*c == 'p')
		print_ft_putpointer_fd((unsigned long long)va_arg(ap, void *), count);
	else if (*c == 'd' || *c == 'i')
		print_ft_putnbr_fd(va_arg(ap, int), count);
	else if (*c == 'u')
		print_ft_putunsignedint_fd(va_arg(ap, unsigned int), count);
	else if (*c == 'x')
		print_lowerx(va_arg(ap, unsigned int), count);
	else if (*c == 'X')
		print_upperx(va_arg(ap, unsigned int), count);
	else if (*c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(const char *ptr, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, ptr);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			print_check_type(++ptr, ap, &count);
			ptr++;
		}
		else
		{
			write(1, ptr, 1);
			ptr++;
			count++;
		}
	}
	return (count);
}
