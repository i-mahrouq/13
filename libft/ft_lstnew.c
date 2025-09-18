#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *root;

    root = (t_list *)malloc(sizeof(t_list));
    if (!root)
        return (NULL);
    root->content = content;
    root->next = NULL;
    return (root);
}