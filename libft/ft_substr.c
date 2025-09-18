#include "libft.h"

char    *ft_substr(char const *s, unsigned int start,size_t len)
{
    char    *substr;
    int     i;

    if (ft_strlen(s) < start)
        return(ft_strdup(""));
    if ((unsigned int *)ft_strlen(s) < start + (unsigned int *)len)
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
    return (substr);
}