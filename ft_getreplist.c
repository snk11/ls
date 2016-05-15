/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2016/05/15 18:10:37 by syusof           ###   ########.fr       */
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
		e->name = pdirent1->d_name;
		e->path = ft_makepath(rep,pdirent1->d_name);
		lstmp = ft_create_lst(e);

		lst_add(&lsta, lstmp);
	}
//	push_swap(&lsta);
//	lsta = lst_sort(lsta, croissant);
//	lstmp = lsta;
	closedir(pdir1);

	return (lsta);
}
