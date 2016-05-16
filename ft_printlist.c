/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/05/16 17:55:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_printlist(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(lstmp) == 0)
			lst_addo(&lst1, lstmp);
			if ( (((t_rep*)(lstmp)->content)->name)[0] != '.')
			{
//				ft_putstr(((t_rep*)((lstmp))->content)->name);
//				ft_putstr("\n");
			}
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if (ft_isdir(lstmp) == 1)
			lst_addo(&lst2, lstmp);
			if ( (((t_rep*)(lstmp)->content)->name)[0] != '.')
			{
//				ft_putstr(((t_rep*)((lstmp))->content)->name);
//				ft_putstr("\n");
			}
		lstmp = lstmp->nextr;
	}
	lst1 = ft_lst_sort(lst1, croissant);
	lst2 = ft_lst_sort(lst2, croissant);
	while (lst1)
	{
		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	while (lst2)
	{
		if ( (((t_rep*)(lst2)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst2))->content)->name);
			ft_putstr("\n");
		}
		lst2 = lst2->next;
	}
}


t_lsto	*ft_printlist2(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(lstmp) == 0)
			lst_addo(&lst1, lstmp);
			if ( (((t_rep*)(lstmp)->content)->name)[0] != '.')
			{
//				ft_putstr(((t_name*)((lstmp))->content)->name);
//				ft_putstr("\n");
			}
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if (ft_isdir(lstmp) == 1)
			lst_addo(&lst2, lstmp);
			if ( (((t_rep*)(lstmp)->content)->name)[0] != '.')
			{
//				ft_putstr(((t_name*)((lstmp))->content)->name);
//				ft_putstr("\n");
			}
		lstmp = lstmp->nextr;
	}
//	lst1 = ft_lst_sort(lst1, croissant);
//	lst2 = ft_lst_sort(lst2, croissant);
	while (lst1)
	{
		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	lstbegio = lst2;
	while (lst2)
	{
		if ( (((t_rep*)(lst2)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst2))->content)->name);
			ft_putstr("\n");
		}
		lst2 = lst2->next;
	}
	/*
	lst2 = lstbegio;
	while (lst2)
	{
		ft_getreplist(((t_rep*)(lst2->content))->path);
		lst2 = lst2->next;
	}
	*/
	return (lstbegio);
}
