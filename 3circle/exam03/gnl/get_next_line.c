#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return NULL;
	i = 0;
	while (i  < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

int	ft_strlcpy(char *dst, char *src, int dst_size)
{
	int	src_len;
	int	i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dst_size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	dst_len;
	int	src_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return NULL;
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, total_len + 1);
	free(s1);
	return (res);
}

int	ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_substr(char *s, int	start, int len)
{
	char	*result;
	int s_len;
	int	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char    *get_next_line(int fd)
{
    static char *storage;
    char        buffer[BUFFER_SIZE + 1];
    char        *line;
    int         read_size;
    int         nl_index;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    if (!storage)
        storage = ft_strdup("");
    if (!storage)
        return (NULL);
        
    while (1)
    {
        read_size = read(fd, buffer, BUFFER_SIZE);
        if (read_size < 0)  // 읽기 오류 발생 시
        {
            free(storage);
            storage = NULL;
            return (NULL);
        }
        if (read_size == 0)  // EOF 도달 시
            break;
            
        buffer[read_size] = '\0';
        storage = ft_strjoin(storage, buffer);
        if (!storage)
            return (NULL);
            
        if (ft_strchr(storage, '\n') > -1)
            break;
    }

    // storage가 비어있는 경우
    if (!storage || storage[0] == '\0')
    {
        free(storage);
        storage = NULL;
        return (NULL);
    }

    nl_index = ft_strchr(storage, '\n');
    if (nl_index > -1)
    {
        line = ft_substr(storage, 0, nl_index + 1);
        char *temp = ft_substr(storage, nl_index + 1, ft_strlen(storage) - nl_index);
        free(storage);
        if (!temp || !line)
        {
            free(temp);
            free(line);
            storage = NULL;
            return (NULL);
        }
        storage = temp;
        return (line);
    }

    // 마지막 줄 처리
    if (storage[0] == '\0')
    {
        free(storage);
        storage = NULL;
        return (NULL);
    }
    
    line = ft_strdup(storage);
    free(storage);
    storage = NULL;
    return (line);
}