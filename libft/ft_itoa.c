#include "libft.h"

const int count_digits(int n)
{
    int i;

    i = 0;
    if (n < 0)
        i++;
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    return i;
}
char *ft_itoa(int nb)
{
    int digits;
    char *res;
    int sign;
    long n;

    n = nb;
    if (n == 0)
    {
        res = ft_strdup("0");
        return res;
    }
    digits = count_digits(n);
    res = malloc(digits + 1);
    if (!res)
        return (NULL);
    
    if (n < 0)
    {
        n *= -1;
        sign = -1;
    }
    res[digits] = '\0';
    while (digits--)
    {
        if(digits == 0 && sign == -1 )
            res[digits] = '-';
        else 
        {
            res[digits] = n % 10 + 48;
            n /= 10;
        }
    }
    
    return res;
}
int main()
{
    printf("%s", ft_itoa(0));
}