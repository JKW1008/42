#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void ft_putstr(char *s, int *cnt)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s++, 1);
		(*cnt)++;
	}
}

void	ft_putnbr(int n, int *cnt)
{
	char c;
	
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", cnt);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*cnt)++;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, cnt);
	c = n % 10 + '0';
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_puthex(unsigned int n, int *cnt)
{
	char *str = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16, cnt);
	write(1, &str[n % 16], 1);
	(*cnt)++;
}

int	ft_printf(const char *s, ...)
{
	va_arg arg;
	int cnt;

	va_start(arg);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (*s == 's')
				ft_putstr(va_arg(arg, char *), &cnt);
			else if (*s == 'd')
				ft_putnbr(va_arg(arg, int), &cnt);
			else if (*s == 'x')
				ft_puthex(va_arg(arg, unsigned int), &cnt);
			else
			{
				write(1, s, 1);
				cnt++;
			}
		}
		else
		{
			write(1, s, 1);
			cnt++;
		}
		s++;
	}
	va_end(arg);
	return cnt;
}
