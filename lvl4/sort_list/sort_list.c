/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 03:29:57 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/16 03:37:02 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *begin;
	int tmp;

	begin = lst;
	while (lst && lst->next)
	{
		if (!(cmp(lst->data, lst->next->data)))
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	lst = begin;
	return (lst);
}
