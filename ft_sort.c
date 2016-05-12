/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:30 by syusof            #+#    #+#             */
/*   Updated: 2016/05/12 14:14:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int croissant(t_lst *lsta)
{
		return (ft_strcmp(((t_name*)(lsta)->content)->name,((t_name*)((lsta)->next)->content)->name) < 0);
}


t_lst		*lst_sort(t_lst *lst, int (*cmp)(t_lst*))
{
	t_lst *lstmp1;
	t_lst *lstmp2;
	t_lst *lstbegi;
	int		ind;

	lstbegi = lst;
	lstmp1 = NULL;
	lstmp2 = NULL;
	ind = 1;
	if (lst == NULL)
		ind = 0;
	while (ind != 0)
	{
		ind = 0;
		lst = lstbegi;
		lstmp1 = lst;
		if (lstbegi->next)
		{
			if ((cmp)(lstbegi) == 0)
			{
				lstmp2 = (lstbegi->next)->next;
				lstmp1 = lstbegi->next;
				(lstbegi->next)->next = lstbegi;
				lstbegi->next = lstmp2;
				lstbegi = lstmp1;
				ind = 1;
			}
			lst = lstbegi;
			lst = lst->next;
		}
		while(lst->next != NULL)
		{
			if ((cmp)(lst) == 0)
			{
				lstmp1->next = lst->next;
				lstmp2 = (lst->next)->next;
				(lst->next)->next = lst;
				lst->next = lstmp2;
				ind = 1;
			}
			lst = lstmp1->next;
			lstmp1 = lst;
			if (lst->next)
				lst = lst->next;
		}

	}
	return (lstbegi);
}
