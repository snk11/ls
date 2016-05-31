/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2016/05/31 15:46:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_ls.h"


t_lst *ft_getreplist(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_rep			*e;
	t_rep			*e2;
	t_lst			*lstmp;
	t_lst			*lstmp2;
	t_lst			*lsta;
	t_lst			*lstb;
	int i;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;

	pdir1 = opendir(rep);



	while ((pdirent1 = readdir(pdir1)))
	{
//		if ((strncmp(pdirent1->d_name,".",1)) && (strncmp(pdirent1->d_name,"..",2)))
//			printf("%s\n",pdirent1->d_name);
		
		if (!(e = (t_rep*)malloc(sizeof(t_rep))))
			return (0);
//		e->name = pdirent1->d_name;
//		e->path = rep;

		if (pdirent1->d_name[0] != '.')
		{
			lstmp = ft_create_lst(e);
			((t_rep*)(lstmp->content))->name = ft_memmove2(pdirent1->d_name);
			((t_rep*)(lstmp->content))->path = ft_memmove2(rep);
			lsta = lst_add(lsta, lstmp);
		}
	}
//	push_swap(&lsta);
//	lsta = lst_sort(lsta, croissant);
//	lstmp = lsta;
	closedir(pdir1);

	return (lsta);
}

t_lst *ft_getreplist4(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_rep			*e;
	t_rep			*e2;
	t_lst			*lstmp;
	t_lst			*lstmp2;
	t_lst			*lsta;
	t_lst			*lstb;
	int i;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;

	pdir1 = opendir(rep);



	while ((pdirent1 = readdir(pdir1)))
	{
//		if ((strncmp(pdirent1->d_name,".",1)) && (strncmp(pdirent1->d_name,"..",2)))
//			printf("%s\n",pdirent1->d_name);
		
		if (!(e = (t_rep*)malloc(sizeof(t_rep))))
			return (0);
//		e->name = pdirent1->d_name;
//		e->path = rep;

//		if (pdirent1->d_name[0] != '.')
		{
			lstmp = ft_create_lst(e);
			((t_rep*)(lstmp->content))->name = ft_memmove2(pdirent1->d_name);
			((t_rep*)(lstmp->content))->path = ft_memmove2(rep);
			lsta = lst_add(lsta, lstmp);
		}
	}
//	push_swap(&lsta);
//	lsta = lst_sort(lsta, croissant);
//	lstmp = lsta;
	closedir(pdir1);

	return (lsta);
}
