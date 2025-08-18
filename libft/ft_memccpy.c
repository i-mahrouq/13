#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    unsigned char *bdst;
    const unsigned char *bsrc;

    bdst = (unsigned char *)dst;
    bsrc = (const unsigned char *)src;
    while (n-- > 0)
    {
        *bdst = *bsrc;
        if (*bsrc == (unsigned char)c)
            return (dst);
        bdst++;
        bsrc++;
    }
    return (NULL);
}