#include "libft.h"
char *ft_strchr(const char *s, int c)
{
    size_t size;
    int i;
    i = 0;
    size = ft_strlen(s) + 1;
    while (*s) 
    {
        if ((unsigned char)*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return (NULL);
}

