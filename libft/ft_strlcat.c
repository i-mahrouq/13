#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dlen;
    size_t slen;

    dlen = ft_strlen(dst);
    slen = ft_strlen(src);
    if(dstsize == 0 || dlen >= dstsize)
        return (slen + dstsize);
    if((slen + dlen) < dstsize)
    {
        ft_memcpy(dst + dlen, src, dstsize - dlen - 1);
        dst[slen + dlen ] = '\0';
    }
    return (slen + dlen);
}