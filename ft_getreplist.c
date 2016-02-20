/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:00:42 by syusof            #+#    #+#             */
/*   Updated: 2016/02/20 14:22:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_ls.h"


t_lst *ft_getreplist(char *rep)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_name			*e;
	t_name			*e2;
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
		
		if (!(e = (t_name*)malloc(sizeof(t_name))))
			return (0);
		e->name = pdirent1->d_name;
		lstmp = create_lst(e);

		lst_add(&lsta, &lstmp);


	}
	push_swap(&lsta);
	lstmp = lsta;
	closedir(pdir1);

	return (lsta);
}
