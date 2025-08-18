#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
int main()
{
    char b[10] = "abcdefjhi";
    ft_bzero(b, 0);
    printf("%s\n", b);
    return 0;
}
