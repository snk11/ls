/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:45:09 by syusof            #+#    #+#             */
/*   Updated: 2016/11/21 20:55:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_r(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstj;
	t_lsto			*lst1;
	t_lsto			*lstibegi;
	int				i;

	lstj = NULL;
	lst1 = NULL;
	ft_print_n(s, lstcmd, ind);
	lst = ft_getreplist(s);
	ft_printname(s, lstcmd, ind);
	lsti = ft_printlist2(lst);
	lstibegi = lsti;
	i = 0;
	while (lsti)
		ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist3);
	/*
	{
		lstj = ft_function_rl1(&lsti, lst, ft_getreplist, ft_printlist3);
		lstibegi = ft_copylst1(lstibegi, lsti, lstj);
		*/
		/*
		t_lsto *lst2;
		lst2 = lstibegi;
		printf("---------\n");
		while (lst2)
		{
			printf("lst2name = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
		*/
		/*
		lsti = ft_curs(lstibegi, i);
		lsti = lsti->next;
		t_lsto *lst2;
		lst2 = lsti;
		printf("---------\n");
		while (lst2)
		{
			printf("lst2name = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
		i++;
	}
	while (lsti && i < 50)
	{
		printf ("i = %d",i);
		lstj = ft_function_rl1(&lsti, lst, ft_getreplist, ft_printlist3);
		if (lstj)
			lstibegi = ft_copylst1(lstibegi, lsti, lstj);
		t_lsto *lst2;
		lst2 = lstibegi;
		printf("---------\n");
		while (lst2)
		{
			printf("lstjname = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
		if (lstj)
			lsti = ft_curs(lstibegi, i);
		lsti = lsti->next;
		*/
		/*
		t_lsto *lst2;
		lst2 = lsti;
		printf("---------\n");
		while (lst2)
		{
			printf("lst2name = %s\n",((t_rep*)lst2->content)->name);
			lst2 = lst2->next;
		}
		*/
		/*
		i++;
	}
	*/
	lstibegi = ft_lst_sort(lstibegi, croissant_pathname);
	lsti = lstibegi;
	while (lsti)
		ft_function_r4(&lsti, lst, ft_getreplist, ft_printlist2);
}
