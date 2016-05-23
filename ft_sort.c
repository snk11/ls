/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:30 by syusof            #+#    #+#             */
/*   Updated: 2016/05/23 22:29:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int croissant(t_lsto *lsta)
{
		return (ft_strcmp(((t_rep*)(lsta)->content)->name,((t_rep*)((lsta)->next)->content)->name) < 0);
}


int croissant_pathname(t_lsto *lsti)
{
		return (ft_strcmp(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti)->content)->name),ft_makepath(((t_rep*)((lsti->next)->content))->path,((t_rep*)((lsti->next)->content))->name)) < 0);
}

t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*))
{
	t_lsto *lstmp1;
	t_lsto *lstmp2;
	t_lsto *lstbegi;
	int		ind;
	long long	count;
	count = 0;
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
		while(lst->next != NULL && count < 999999)
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
			count++;
		}
	}
	return (lstbegi);
}


t_lsto		*ft_lst_sort1(t_lsto *lst)
{
	t_lsto	*lst1;

	lst1 = ft_lst_sort(lst,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	lst1 = ft_lst_sort(lst1,croissant);
	return (lst1);
}



t_lsto		*ft_lst_sort2(t_lsto *lst)
{
	t_lsto	*lst1;

	lst1 = ft_lst_sort(lst,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	lst1 = ft_lst_sort(lst1,croissant_pathname);
	return (lst1);
}
