/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:01 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 18:51:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_run(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int inderror;
	t_lsto			*lst;
	t_lsto			*lstj;

	lst = NULL;
	lstj = NULL;
	ind->indposition = 0;
	ind->indexyet = 0;
	ind->indexyet2 = 0;
	ind->indexyet3 = 0;
	ind->indexyet4 = 0;

	while(lst1)
	{
		ind->index1 = ft_getindex(lst1,lstcmd);
		ind->indposition++;
		inderror = 0;
		if (!opendir((char*)(lst1->content)))
			inderror = 1;
		if (inderror == 0 && ft_checkhyphen(lst1,lstcmd,ind) == 0)
		{
			if(ft_ls_run_p1(lst1, lstcmd, ind))
			{
			}
			else
			{
				ft_print_n((char*)lst1->content,lstcmd,ind);
				lst = ft_getreplist((char*)(lst1->content));
				ft_printname((char*)lst1->content,lstcmd,ind);
				lstj = ft_printlist2(lst);
			}
		}
		lst1 = lst1->next;
	}
}
