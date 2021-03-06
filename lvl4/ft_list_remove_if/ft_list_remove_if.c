/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 03:01:41 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/16 03:10:54 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;

	while ((*begin_list) && !(cmp((*begin_list)->data, data_ref)))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	lst = *begin_list;
	while (lst && lst->next)
	{
		if (!cmp(lst->next->data, data_ref))
		{
			tmp = lst->next;
			lst->next = tmp->next;
			free(tmp);
		}
		if (lst->next)
			lst = lst->next;
	}
}
