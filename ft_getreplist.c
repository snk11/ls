/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2017/01/21 03:03:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*ft_getreplist(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	t_rep			*e;
	t_lsto			*lstmp;
	t_lsto			*lsta;

	lsta = NULL;
	lstmp = NULL;
	pdir1 = opendir(rep);
	while ((pdirent1 = readdir(pdir1)))
	{
		if (!(e = (t_rep*)malloc(sizeof(t_rep))))
			return (0);
		if (pdirent1->d_name[0] != '.')
		{
			e->name = ft_memmove2(pdirent1->d_name);
			e->path = ft_memmove2(rep);
			lstmp = ft_create_lsto2(e);
			ft_free2(&e);
			lst_addo(&lsta, &lstmp);
			ft_freelst2(&lstmp);
		}
	}
	closedir(pdir1);
	return (lsta);
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
	pdir1 = opendir(rep);
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
	return (lsta);
}

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
