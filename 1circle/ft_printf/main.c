#include <stdio.h>
#include "./ft_printf.h"

int	main()
{
	int a = 0;
	ft_printf("%p", &a);
	printf("printf = %p\n", &a);
	return (0);
}
