#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dlen;
    size_t slen;

    dlen = ft_strlen(dst);
    slen = ft_strlen(src);
    if (dstsize == 0)
        return (slen);
    if(dlen >= dstsize)
        return (dstsize + slen);
    if((slen + dlen) < dstsize)
    {
        ft_memcpy(dst + dlen, src, slen);
        dst[slen + dlen ] = '\0';
    }
    else
    {
        ft_memcpy(dst + dlen, src, dstsize - dlen - 1);
        dst[dstsize - dlen - 1] = '\0';
    }
    return (dlen + slen);
}

