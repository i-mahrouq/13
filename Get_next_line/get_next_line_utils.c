#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

void    *ft_calloc(size_t count, size_t size)
{
    void            *ptr;
    unsigned char   *p;
    size_t          total;

    total = count * size;
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    p = (unsigned char *)ptr;
    while (total--)
        *p++ = 0;
    return (ptr);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *bdst;
    const unsigned char *bsrc;

    if (!dst && !src)
        return (0);
    bdst = (unsigned char *)dst;
    bsrc = (const unsigned char *)src;
    while (n-- > 0)
        *bdst++ = *bsrc++;
    return (dst);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  len;
    char    *dst;

    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    dst = (char *)malloc(len);
    if (!dst)
        return (NULL);
    ft_memcpy(dst, s1, ft_strlen(s1));
    ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
    dst[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return ((char *)dst);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}
