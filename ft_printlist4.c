/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:36:08 by syusof            #+#    #+#             */
/*   Updated: 2017/03/09 03:12:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printlist14(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lst3;
	t_loption	loption;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, decreasing);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void		ft_printlist15(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
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

t_lsto		*ft_printlist16(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lst3;
	t_loption	loption;

	ft_printlist8_p1(&lst1, &lst2);
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant);
	lst3 = ft_lst_sort(lst3, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
	return (lst3);
}

t_lsto		*ft_printlist17(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lst3;
	t_loption	loption;

	ft_printlist8_p1(&lst1, &lst2);
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lst3 = ft_lst_sort(lst3, decreasing_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
	return (lst3);
}

t_lsto		*ft_printlist18(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lst3;
	t_loption	loption;

	ft_printlist8_p1(&lst1, &lst2);
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, decreasing);
	lst3 = ft_lst_sort(lst3, decreasing);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
	return (lst3);
}
