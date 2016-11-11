/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:33:08 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 14:18:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*))
{
	t_lsto *lstmp1;
	t_lsto *lstmp2;
	t_lsto *lstbegi;
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
		ft_lst_sort_p1(&lst, &lstbegi, &lstmp1 ,&ind,cmp);
		ft_lst_sort_p2(&lst, &lstbegi, &lstmp1 ,&ind,cmp);
	}
	return (lstbegi);
}

void		ft_lst_sort_p1(t_lsto **lst, t_lsto **lstbegi, t_lsto **lstmp1,int *ind ,int (*cmp)(t_lsto*))
{
	t_lsto	*lstmp2;

	*lst = *lstbegi;
	*lstmp1 = *lst;
	if ((*lstbegi)->next)
	{
		if ((cmp)(*lstbegi) == 0)
		{
			lstmp2 = ((*lstbegi)->next)->next;
			*lstmp1 = (*lstbegi)->next;
			((*lstbegi)->next)->next = *lstbegi;
			(*lstbegi)->next = lstmp2;
			*lstbegi = *lstmp1;
			*ind = 1;
		}
		*lst = *lstbegi;
		*lst = (*lst)->next;
	}
}


void		ft_lst_sort_p2(t_lsto **lst, t_lsto **lstbegi, t_lsto **lstmp1,int *ind ,int (*cmp)(t_lsto*))
{
	t_lsto	*lstmp2;

	while((*lst)->next != NULL)
	{
		if ((cmp)(*lst) == 0)
		{
			(*lstmp1)->next = (*lst)->next;
			lstmp2 = ((*lst)->next)->next;
			((*lst)->next)->next = *lst;
			(*lst)->next = lstmp2;
			*ind = 1;
		}
		*lst = (*lstmp1)->next;
		*lstmp1 = *lst;
		if ((*lst)->next)
			*lst = (*lst)->next;
	}
}
