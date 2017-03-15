/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:01 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 13:52:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_run(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd)
{
	int inderror;

	ind->indposition = 0;
	ind->indexyet4 = 0;
	while (lst1)
	{
		ind->index1 = ft_getindex(lst1, lstcmd);
		ind->indposition++;
		inderror = 0;
		if (!opendir((char*)(lst1->content)))
			inderror = 1;
		if (inderror == 0)
		{
			if (ft_ls_run_p1(lst1, lstcmd, ind))
				;
			else
				ft_ls_run_p2(lst1, lstcmd, ind);
		}
		else if (ft_isdir((char*)lst1->content))
			ft_ls_run_p0(lst1, ind, lstcmd);
		lst1 = lst1->next;
	}
}

void	ft_ls_run_p0(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd)
{
	ft_printname((char*)lst1->content, lstcmd, ind);
	ft_putstr_fd("ls: ", 2);
	opendir((char*)lst1->content);
	perror(ft_cutname_lcaselink((char*)lst1->content));
}
