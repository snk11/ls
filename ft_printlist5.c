/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:44:29 by syusof            #+#    #+#             */
/*   Updated: 2017/03/09 03:16:56 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto	*ft_printlist19(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst3 = ft_lst_sort(lst3, decreasing);
	return (lst3);
}

t_lsto	*ft_printlist20(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst3 = ft_lst_sort(lst3, decreasing);
	return (lst3);
}

void	ft_printlist21(t_lsto *lstmp)
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

t_lsto	*ft_printlist22(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst3 = ft_lst_sort(lst3, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
	return (lst3);
}

t_lsto	*ft_printlist23(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	while (lstmp)
	{
		ft_printlist8_p2(lstmp, &lst1, &lst2, &lst3);
		lstmp = lstmp->next;
	}
	lst3 = ft_lst_sort(lst3, croissant_time);
	return (lst3);
}
