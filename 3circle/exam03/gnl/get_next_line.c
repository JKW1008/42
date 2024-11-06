#include "get_next_line.h"

char *ft_strdup(char *s)
{
	int len;
	char	*res;

	while (s[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	static int read;
	static int n;
	char res[50000];
	int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (n >= read)
		{
			read = read(fd, buff, BUFFER_SIZE);
			n = 0;
			if (read <= 0)
				break ;
		}
		if (res[i] == '\n')
			break ;
		res[i] = buff[n++];
		i++;
	}
	res[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(res));
}
