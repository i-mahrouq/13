#include "libft.h"

char    *ft_substr(char const *s, unsigned int start,size_t len)
{
    char    *substr;
    size_t     i;

    if (!s)
        return (NULL);
    if (ft_strlen(s) < start)
        return(ft_strdup(""));
    if (ft_strlen(s) < start + len)
        len = ft_strlen(s) - start;
    substr = (char *)malloc(len + 1);
    if(!substr)
        return(NULL);
    i = 0;
    while(i <  len)
    {
        substr[i] = s[i + start];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}