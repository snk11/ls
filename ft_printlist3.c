/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:22:26 by syusof            #+#    #+#             */
/*   Updated: 2017/02/01 02:33:21 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist9(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
}

t_lsto	*ft_printlist10(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
	return (lstbegio);
}

t_lsto	*ft_printlist11(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;

	lst1 = NULL;
	lst2 = NULL;
	while (lstmp)
	{
		if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, &lstmp);
		else if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, &lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lstbegio = lst2;
	return (lstbegio);
}

t_lsto	*ft_printlist12(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, decreasing);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
	return (lstbegio);
}

void	ft_printlist13(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_loption	loption;

	lst1 = NULL;
	lst2 = NULL;
	while (lstmp)
	{
		if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, &lstmp);
		else if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, &lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}
