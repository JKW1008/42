char    *return_line(char **result)
{
    char    *temp;
    char    *new_line;

    int d = ft_strchr(*result, '\n');
    if (d > -1)
    {
        temp = ft_substr(*result, 0, d + 1);
        new_line = ft_substr(*result, d + 1, ft_strlen(*result) - d);
        //free(*result);
        *result = new_line;
        return (temp);
    }
    else
    {
        printf("no \\n\n");
        temp = ft_strdup(*result);
        //free(*result);
        result = NULL;
        return (temp);
    }
}