#include "libft.h"

char   *ft_strrchr(const char *s, int c)
{
    size_t len;

    len = strlen(s);
    while(len != 0 && s[len] != (char)c)
        len--;
    if(s[len] == c)
        return ((char *)(s + len));
    return (0);
}