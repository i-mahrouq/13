#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *bdst;
    const unsigned char *bsrc;

    if (!dst && !src)
		return (0);
    bdst = (unsigned char *)dst;
    bsrc = (const unsigned char *)src;
    while (n-- > 0)
    {
        *bdst++ = *bsrc++;
    }
    return (dst);
}