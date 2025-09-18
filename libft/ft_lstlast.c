#include "libft.h"

int ft_lstsize(t_list *lst);

t_list *ft_lstlast(t_list *lst)
{
    int size;
    int i;

    i = 0;
    size = ft_lstsize(lst);
    while (lst)
    {
        lst = lst -> next;
    }
    return lst;
}