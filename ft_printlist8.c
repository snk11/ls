/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:46:21 by syusof            #+#    #+#             */
/*   Updated: 2017/02/09 12:24:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist34(t_lsto *lstmp)
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
		else
			lst_addo(&lst2, &lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void	ft_printlist37(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void	ft_printlist41(t_lsto *lstmp)
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
		else
			lst_addo(&lst2, &lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void	ft_printlist43(t_lsto *lstmp)
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
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void	ft_printlist44(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, decreasing);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}
