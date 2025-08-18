#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    size_t llen;

    llen = ft_strlen(little);
    i = 0;
    if (llen == 0)
        return ((char *)big);
    if(llen > ft_strlen(big))
        return (NULL);
    while (i + llen <= len)
    {
        j = 0;
        while (big[i + j] && i + j < len && big[i + j] == little[j])
            j++;
        if (!little[j])
            return ((char *)(big + i));
        i++;
    }
    return (NULL);
}
