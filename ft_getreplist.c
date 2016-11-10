/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 16:08:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_ls.h"


t_lsto *ft_getreplist(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_rep			*e;
	t_rep			*e2;
	t_lsto			*lstmp;
	t_lsto			*lstmp2;
	t_lsto			*lsta;
	t_lsto			*lstb;
	int i;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;
	pdir1 = opendir(rep);
	while ((pdirent1 = readdir(pdir1)))
	{
		if (!(e = (t_rep*)malloc(sizeof(t_rep))))
			return (0);
		if (pdirent1->d_name[0] != '.')
		{
			lstmp = ft_create_lsto(e);
			((t_rep*)(lstmp->content))->name = pdirent1->d_name;
			((t_rep*)(lstmp->content))->path = rep;
			lst_addo(&lsta, lstmp);
		}
		if(e)
		{
			free(e);
			e = NULL;
		}
	}
	closedir(pdir1);
	return (lsta);
}

t_lsto *ft_getreplist4(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_rep			*e;
	t_rep			*e2;
	t_lsto			*lstmp;
	t_lsto			*lstmp2;
	t_lsto			*lsta;
	t_lsto			*lstb;
	int i;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;
	pdir1 = opendir(rep);
	while ((pdirent1 = readdir(pdir1)))
	{
		if (!(e = (t_rep*)malloc(sizeof(t_rep))))
			return (0);
		lstmp = ft_create_lsto(e);
		((t_rep*)(lstmp->content))->name = ft_memmove2(pdirent1->d_name);
		((t_rep*)(lstmp->content))->path = ft_memmove2(rep);
		lst_addo(&lsta, lstmp);
	}
	closedir(pdir1);

	return (lsta);
}

t_lsto	*ft_getreplisto4(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lsto	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		else if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2, croissant);
	lstbegio = lst2;
	return (lstbegio);
}
