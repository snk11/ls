/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 14:23:05 by syusof           ###   ########.fr       */
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

	ft_getreplist_p1(&lsta, &lstmp);
	if ((pdir1 = opendir(rep)))
	{
		while ((pdirent1 = readdir(pdir1)))
		{
			if (!(e = (t_rep*)malloc(sizeof(t_rep))))
				return (0);
			if (pdirent1->d_name[0] != '.')
			{
				ft_getreplist_p2(e, rep, pdirent1->d_name);
				lstmp = ft_create_lsto2(e);
				ft_free2(&e);
				lst_addo(&lsta, &lstmp);
				ft_freelst2(&lstmp);
			}
		}
		closedir(pdir1);
	}
	return (lsta);
}

void		ft_getreplist_p1(t_lsto **lsta, t_lsto **lstmp)
{
	*lsta = NULL;
	*lstmp = NULL;
}

void		ft_getreplist_p2(t_rep *e, char *rep, char *s)
{
	e->name = ft_memmove2(s);
	e->path = ft_memmove2(rep);
}
