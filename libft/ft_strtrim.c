#include "libft.h"

static int is_charset(char c, char *set)
{
    int     i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1); 
        i++;
    }
    return (0);
}


char *ft_strtrim(char const *s1, char const *set)
{
    char    *s2;
    size_t  start;
    size_t  end;

    start = 0;
    while (s1[start] && is_charset(s1[start], (char *)set))
        start++;
    end = ft_strlen(s1);
    if (end > 0)
        end--;
    while (is_charset(s1[end], (char *)set) && start < end )
        end--;

    s2 = (char *)malloc(end - start + 2);
    if (!s2)
        return(NULL);
    ft_memcpy(s2, s1 + start,end - start + 1);
    s2[end - start + 1] = '\0';
    return (s2);
}