#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
    unsigned char *bdst;
    const unsigned char *bsrc;

    if(dst > src)
    {
        bdst = (unsigned char *)dst + (n - 1);
        bsrc = (const unsigned char *)src + (n - 1);
        while (n-- > 0)
        {
            *bdst-- = *bsrc--;
        }
    }
    else
    {
        bdst = (unsigned char *)dst;
        bsrc = (const unsigned char *)src ;
        while (n-- > 0)
        {
            *bdst++ = *bsrc++;
        }
    }
    return (dst);
}