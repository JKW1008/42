#include <stdlib.h>
#include <stdarg.h>

void	ft_putstr(char *s, int *cnt)
{
	int	i;
	if (!s)
		ft_putstr("(null);", cnt);
	i = 0;
	while (s[i])
	{
		write(1, s[i], 1);
		(*cnt)++;
		i++;
	}
}

void	ft_putnbr(int n, int *cnt)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", cnt);
		return ;
	}
	if (n < 0)
	{
		ft_putstr("-", cnt);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, cnt);
	}
	char c = n % 10 + '0';
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_puthex(unsigned int n, int *cnt)
{
	char *str = "0123456789abcdef";

	if (n >= 16)
	{
		ft_puthex(n % 16, cnt);
	}
	write(1, str[n % 16], 1);
	(*cnt)++;
}
int	ft_pritnf(const char *form, ...)
{
	va_list args;
	int		i;
	int		cnt;

	i = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			if (form[i] == 's')
				ft_putstr(va_arg(char *, args), &cnt);
			else if (form[i] == 'd')

		}
	}
}