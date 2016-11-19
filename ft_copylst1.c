/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copylst1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:16:42 by syusof            #+#    #+#             */
/*   Updated: 2016/11/19 13:17:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*lst_addo42(t_lsto *toplist, t_lsto *lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp1;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;
	t_lsto		*lstw;

	lstmp = NULL;
	lstmp1 = NULL;
	lstmp2 = NULL;
	lstbegi = NULL;
	lstw = NULL;
	lsttopbegi = toplist;
	lstmp2 = lsttopbegi;
	//	lst_addo_between_p1(&toplist, &lst1);
	lstmp2 = toplist;
	while (lst1)
	{
		lstmp = ft_create_lsto((lst1)->content);
		ft_lst_fullfield(lst1, &lstmp);
		lst_addo(&lstw, lstmp);
		lst1 = lst1->next;
	}
	if(toplist == NULL)
	{
		lstmp = ft_create_lsto((lst1)->content);
		ft_lst_fullfield(lst1, &lstmp);
//		**toplist = lstw;
	}
	else if (toplist)
	{
		lstmp1 = lstw;
		while (lstmp1 && lstmp1->next)
		{
			lstmp1 = lstmp1->next;
		}
//		if(lstmp1)
//			lstmp1->next = (toplist)->next;
//		if(lstw)
//			(**toplist)->next = lstw;
	}
	return (lstw);

	//	lsttopbegi = lst_addo_between_p2(&lsttopbegi, &lst1);
//	**toplist = lsttopbegi;
}

t_lsto	*ft_reverse_lst(t_lsto *lstmp)
{
	t_rep	*e;
	t_lsto	*lsta2;
	t_lsto	*lstmp1;
	t_lsto	*lstmp2;

	e = NULL;
	lstmp2 = NULL;
	lsta2 = NULL;
	lstmp1 = lstmp;
	while (lstmp1)
	{
		e = (t_rep*)malloc(sizeof(t_rep));
//		e->val = ((t_numb*)(lstmp1)->content)->val;
		lstmp2 = ft_create_lsto(e);
		ft_lst_fullfield(lstmp1, &lstmp2);
		lst_addo(&lsta2, lstmp2);
		lstmp1 = lstmp1->next;
		free(e);
		e = NULL;
		ft_freelst(&lstmp2);
	}
	return (lsta2);
}
t_lsto		*ft_copylst1(t_lsto *lstbegi, t_lsto *lsti,t_lsto *lstj)
{
	t_lsto	*lst3;
	t_lsto	*lst1;
	t_lsto	*lstw;
	t_lsto	*lstmp;

	lst3 = NULL;
	lstw = NULL;
			printf("lstiname = %s\n",((t_rep*)lsti->content)->name);
		t_lsto *lst2;
		lst2 = lstbegi;
		while (lst2)
		{
			printf("lst2name = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
		lst1 = lstbegi;
//	while (lst1 && lst1 != lsti)
/*
	while (lst1)
	{
		lstmp = ft_create_lsto((lst1)->content);
		ft_lst_fullfield(lst1, &lstmp);
		lst_addo(&lstw, lstmp);
		lst1 = lst1->next;
	}
	*/
//	while (lstbegi && lstbegi != lsti)
	while (lstbegi)
	{
		lstmp = ft_create_lsto((lstbegi)->content);
		ft_lst_fullfield(lstbegi, &lstmp);
		lst_addo(&lst3, lstmp);
		lstbegi = lstbegi->next;
	}
	/*
	if(lstbegi && lstbegi == lsti)
		lst3 = lst_addo_down(lst3, lstbegi);
	*/
	while (lstj)
	{
		lst_addo(&lst3, lstj);
		lstj = lstj->next;
	}
		if (lst3)
			lst3 = ft_reverse_lst(lst3);
		lst2 = lst3;
		while (lst2)
		{
			printf("lst1name = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
//		lst3 = NULL;
	return (lst3);
}
