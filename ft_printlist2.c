/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:55:39 by syusof            #+#    #+#             */
/*   Updated: 2017/03/14 17:18:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printlist5(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
	lst2 = ft_lst_sort(lst2, decreasing);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
}

void		ft_printlist6(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
}

void		ft_printlist7(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	if (lst1)
		ft_printlist7_p1(lst1);
	ft_init2(&loption);
	ft_width(lst1, &loption);
	ft_wl(lst1, loption);
}

void		ft_printlist7_p1(t_lsto *lstmp2)
{
	struct stat		sb;
	unsigned long	l;

	l = 0;
	while (lstmp2)
	{
		if (lstat(ft_makepath(((t_rep*)(lstmp2->content))->path,
						((t_rep*)(lstmp2->content))->name), &sb) == 0)
			l = l + sb.st_blocks;
		lstmp2 = lstmp2->next;
	}
	ft_putstr("total ");
	ft_putulongnbr(l);
	ft_putstr("\n");
}

t_lsto		*ft_printlist8(t_lsto *lstmp)
{
	t_lsto		*lst1;
	t_lsto		*lst2;
	t_lsto		*lst3;
	t_loption	loption;

	lst3 = NULL;
	ft_printlist8_p1(&lst1, &lst2);
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


void		ft_printlist8_p2(t_lsto *lstmp, t_lsto **lst1, t_lsto **lst2, t_lsto **lst3)
{
	char	*s1;

		s1 = ft_makepath(((t_rep*)(lstmp->content))->path,
						((t_rep*)(lstmp->content))->name);
		if (ft_isdir(s1) == 0)
			lst_addo(lst1, &lstmp);
//		else if (ft_isdir(s1) == 1 && ft_checkdev(((t_rep*)(lstmp->content))->path) == 0)
		else if (ft_isdir(s1) == 1)
		{
			lst_addo(lst2, &lstmp);
			if (ft_islnk(s1) == 0)
				lst_addo(lst3, &lstmp);
		}
}
