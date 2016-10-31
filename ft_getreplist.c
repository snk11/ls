/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2016/10/31 23:54:25 by syusof           ###   ########.fr       */
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
	char			*s1;
	char			*s2;

	s1 = NULL;
	s2 = NULL;
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
			s1 = pdirent1->d_name;
			s2 = rep;
			lstmp = ft_create_lsto(e,s1,s2);
			lst_addo(&lsta, lstmp);
		}
	}
//	push_swap(&lsta);
//	lsta = lst_sort(lsta, croissant);
//	lstmp = lsta;
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
	char			*s1;
	char			*s2;

	s1 = NULL;
	s2 = NULL;
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
			s1 = pdirent1->d_name;
			s2 = rep;
			lstmp = ft_create_lsto(e,s1,s2);
			lst_addo(&lsta, lstmp);
		}
	}
//	push_swap(&lsta);
//	lsta = lst_sort(lsta, croissant);
//	lstmp = lsta;
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

