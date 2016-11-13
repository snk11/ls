/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:55:27 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 08:32:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto	*ft_printlist29(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, croissant_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
	return (lstbegio);
}

t_lsto	*ft_printlist30(t_lsto *lstmp)
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
			lst_addo(&lst1, lstmp);
		else if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lstbegio = lst2;
	return (lstbegio);
}

t_lsto	*ft_printlist31(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lstbegio;
	t_loption	loption;

	lst1 = NULL;
	lst2 = NULL;
	while (lstmp)
	{
		if (ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		else
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
	return (lstbegio);
}
