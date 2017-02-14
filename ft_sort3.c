/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:33:08 by syusof            #+#    #+#             */
/*   Updated: 2017/02/14 17:35:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			decreasing_time(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0
			&& sa.st_mtime >= sb.st_mtime)
	{
		if (sa.st_mtime > sb.st_mtime)
			return (1);
		if (decreasing_time_p1(sa, sb))
		{
			if (sa.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
					&& ft_strcmp(s1, s2) <= 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int			decreasing_time_p1(struct stat sa, struct stat sb)
{
	if (sa.st_mtime == sb.st_mtime
			&& sa.st_mtimespec.tv_nsec >= sb.st_mtimespec.tv_nsec)
		return (1);
	return (0);
}

t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*))
{
	t_lsto		*lstmp1;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_sort		s;

	lstbegi = lst;
	lstmp1 = NULL;
	lstmp2 = NULL;
	s.ind = 1;
	s.f = cmp;
	if (lst == NULL)
		s.ind = 0;
	while (s.ind != 0)
	{
		s.ind = 0;
		lst = lstbegi;
		ft_lst_sort_p1(&lst, &lstbegi, &lstmp1, &s);
		ft_lst_sort_p2(&lst, &lstmp1, &s);
	}
	return (lstbegi);
}

void		ft_lst_sort_p1(t_lsto **lst, t_lsto **lstbegi,
		t_lsto **lstmp1, t_sort *s)
{
	t_lsto	*lstmp2;

	*lst = *lstbegi;
	*lstmp1 = *lst;
	if ((*lstbegi)->next)
	{
		if ((s->f)(*lstbegi) == 0)
		{
			lstmp2 = ((*lstbegi)->next)->next;
			*lstmp1 = (*lstbegi)->next;
			((*lstbegi)->next)->next = *lstbegi;
			(*lstbegi)->next = lstmp2;
			*lstbegi = *lstmp1;
			s->ind = 1;
		}
		*lst = *lstbegi;
		*lst = (*lst)->next;
	}
}

void		ft_lst_sort_p2(t_lsto **lst, t_lsto **lstmp1, t_sort *s)
{
	t_lsto	*lstmp2;

	while ((*lst)->next != NULL)
	{
		if ((s->f)(*lst) == 0)
		{
			(*lstmp1)->next = (*lst)->next;
			lstmp2 = ((*lst)->next)->next;
			((*lst)->next)->next = *lst;
			(*lst)->next = lstmp2;
			s->ind = 1;
		}
		*lst = (*lstmp1)->next;
		*lstmp1 = *lst;
		if ((*lst)->next)
			*lst = (*lst)->next;
	}
}
