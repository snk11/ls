/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:49:11 by syusof            #+#    #+#             */
/*   Updated: 2017/03/09 03:31:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist24(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

t_lsto	*ft_printlist25(t_lsto *lstmp)
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

t_lsto	*ft_printlist26(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst3 = ft_lst_sort(lst3, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
	return (lst3);
}

t_lsto	*ft_printlist27(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;
	t_lsto	*lstbegio;

	lst1 = NULL;
	lst2 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lstbegio = lst2;
	return (lstbegio);
}

t_lsto	*ft_printlist28(t_lsto *lstmp)
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
