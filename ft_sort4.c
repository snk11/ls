/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:50:45 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 22:29:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int		croissant_pathname(t_lsto *lsti)
{
	return (ft_strcmp(ft_makepath(((t_rep*)(lsti->content))->path,
					((t_rep*)(lsti)->content)->name),
				ft_makepath(((t_rep*)((lsti->next)->content))->path,
					((t_rep*)((lsti->next)->content))->name)) <= 0);
}
