/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:17:59 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 17:03:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*ft_getreplist5(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	t_rep			*e;
	t_getr			getr1;

	getr1.lsta = NULL;
	getr1.lstmp = NULL;
	if (!(e = (t_rep*)malloc(sizeof(t_rep))))
		return (0);
	e->path = ft_cutpath_lcaselink(rep);
	if ((pdir1 = opendir(e->path)))
	{
		while ((pdirent1 = readdir(pdir1)))
		{
			if (ft_strcmp(pdirent1->d_name, ft_cutname_lcaselink(rep)) == 0)
			{
				if (pdirent1->d_name[0] != '.')
					ft_getreplist5_p1(rep, e, &getr1);
			}
		}
		closedir(pdir1);
	}
	return (getr1.lsta);
}

void		ft_getreplist5_p1(char *rep, t_rep *e, t_getr *getr1)
{
	e->name = ft_memmove2(rep);
	getr1->lstmp = ft_create_lsto2(e);
	ft_free2(&e);
	lst_addo(&(getr1->lsta), &(getr1->lstmp));
	ft_freelst2(&(getr1->lstmp));
}

t_lsto		*ft_getreplist4(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	t_rep			*e;
	t_lsto			*lstmp;
	t_lsto			*lsta;

	lsta = NULL;
	lstmp = NULL;
	if ((pdir1 = opendir(rep)))
	{
		while ((pdirent1 = readdir(pdir1)))
		{
			if (!(e = (t_rep*)malloc(sizeof(t_rep))))
				return (0);
			e->name = ft_memmove2(pdirent1->d_name);
			e->path = ft_memmove2(rep);
			lstmp = ft_create_lsto2(e);
			lst_addo(&lsta, &lstmp);
		}
		closedir(pdir1);
	}
	return (lsta);
}
/*
t_lsto		*ft_getreplisto4(t_lsto *lstmp)
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
	lst2 = ft_lst_sort(lst2, croissant);
	lstbegio = lst2;
	return (lstbegio);
}
*/
