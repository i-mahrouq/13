#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *arr;
    int i;

    if (!s || !f)
        return (NULL);
    arr = (char *)malloc(ft_strlen(s) + 1);
    if (!arr)
        return NULL;
    i = 0;
    while (s[i])
    {
        arr[i] = f(i, s[i]);
        i++;
    }
    arr[i] = '\0';
    return (arr);
}