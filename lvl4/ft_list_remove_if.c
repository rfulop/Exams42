#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
  t_list *lst;
  t_list *tmp;

  while (*begin_list && (!(cmp((*begin_list)->data, data_ref) == 0)))
  {
    tmp = *begin_list;
    *begin_list = (*begin_list)->next;
    free(tmp);
  }
  lst = *begin_list;
  while (lst && lst->next)
  {
    if (!(cmp(lst->data, data_ref)))
    {
      tmp = lst->next;
      lst->next = tmp->next;
      free(tmp);
    }
    if (lst->next)
      lst = lst->next;
  }
}
