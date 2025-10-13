#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len;
    char    *dst;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    dst = (char *)malloc(len);
    if (!dst)
        return (NULL);
    ft_memcpy(dst, s1, ft_strlen(s1));
    ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
    dst[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return ((char *)dst);
}