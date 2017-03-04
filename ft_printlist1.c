/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:33:34 by syusof            #+#    #+#             */
/*   Updated: 2017/03/04 17:17:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	while (lst1)
	{
		if ((((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist_p1(t_lsto *lstmp, t_lsto **lst1, t_lsto **lst2)
{
	char	*s1;

	s1 = NULL;
	while (lstmp)
	{
		s1 = ft_makepath(((t_rep*)(lstmp->content))->path,
				((t_rep*)(lstmp->content))->name);
		if (ft_checkdir(s1) == 0)
			lst_addo1(&lst1, lstmp);
		else if (ft_checkdir(s1) == 1)
			lst_addo1(&lst2, lstmp);
		lstmp = lstmp->next;
	}
}

void	ft_printlist_p2(t_lsto *lstmp, t_lsto **lst1, t_lsto **lst2)
{
	char	*s1;

	s1 = NULL;
	while (lstmp)
	{
		s1 = ft_makepath(((t_rep*)(lstmp->content))->path,
				((t_rep*)(lstmp->content))->name);
		if (ft_checkdir(s1) == 0)
			lst_addo1(&lst1, lstmp);
		else if (ft_checkdir(s1) == 1)
			lst_addo1(&lst2, lstmp);
		lstmp = lstmp->next;
	}
}

void	ft_printlist_p3(t_lsto *lstmp, t_lsto **lst1, t_lsto **lst2, t_lsto **lst3)
{
	char	*s1;

	s1 = NULL;
	while (lstmp)
	{
		s1 = ft_makepath(((t_rep*)(lstmp->content))->path,
				((t_rep*)(lstmp->content))->name);
		if (ft_isdir(s1) == 0)
			lst_addo1(&lst1, lstmp);
		else if (ft_isdir(s1) == 1)
		{
			lst_addo1(&lst2, lstmp);
			if (ft_islnk(s1) == 0)
				lst_addo1(&lst3, lstmp);
		}
		lstmp = lstmp->next;
	}
}

t_lsto	*ft_printlist2(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
	lst2 = ft_lst_sort(lst2, croissant);
	lst3 = ft_lst_sort(lst3, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
	return (lst3);
}

t_lsto	*ft_printlist3(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lst3;

	lst1 = NULL;
	lst2 = NULL;
	lst3 = NULL;
	ft_printlist_p3(lstmp, &lst1, &lst2, &lst3);
	lst3 = ft_lst_sort(lst3, croissant);
	return (lst3);
}

void	ft_printlist4(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;

	lst1 = NULL;
	lst2 = NULL;
	ft_printlist_p1(lstmp, &lst1, &lst2);
	lst2 = ft_lst_sort(lst2, croissant);
	lst1 = lst_addo_down(lst1, lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	while (lst1)
	{
		ft_putstr(((t_rep*)((lst1))->content)->name);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
}
