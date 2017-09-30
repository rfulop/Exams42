#include "ft_list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
  int nb;
  t_list *tmp;

  tmp = lst;
  while (lst->next)
  {
    if (!(cmp(lst->data, lst->next->data)))
    {
      nb = lst->data;
      lst->data = lst->next->data;
      lst->next->data = nb;
      lst = tmp;
    }
    else
      lst = lst->next;
  }
  lst = tmp;
  return lst;
}
