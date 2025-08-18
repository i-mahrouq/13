#include <libft.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t slen;

    slen = ft_strlen(src);
    if (dstsize >= (slen + 1))
    {
        ft_memcpy(dst, src, slen);
        dst[slen] = '\0';
    }
    else if (dstsize != 0)
    {
        ft_memcpy(dst, src, dstsize - 1);
        dst[dstsize - 1] = '\0';
    }
    return (slen);    
}