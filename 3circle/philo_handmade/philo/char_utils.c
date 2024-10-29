/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:49:57 by kjung             #+#    #+#             */
/*   Updated: 2024/10/29 22:58:53 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
	}
	if (n == -2147483648)
	{
		ft_putchar('2', fd);
		n = -(n % 1000000000);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
		ft_putchar(n + '0', fd);
}
