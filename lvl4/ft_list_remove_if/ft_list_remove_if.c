#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *lst;

	while ((*begin_list) && (!(cmp((*begin_list)->data, data_ref))))
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
			tmp = lst;
			lst = lst->next;
			free(tmp);
		}
		if (lst->next)
			lst = lst->next;
	}
}
