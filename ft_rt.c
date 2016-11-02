/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:30:37 by syusof            #+#    #+#             */
/*   Updated: 2016/11/02 10:58:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_rt(char *s, t_lsto *lstcmd,t_ind *ind)
{

	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist10(lst);
	lstibegi = lsti;
	while (lsti)
	{
		if(stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb) == 0)
		{
			if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRGRP))
				lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			if(lst && ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRGRP))
			{
				lstj = ft_printlist11(lst);
				lsti = lst_addo_between(lsti,lstj);
			}
		}
		lsti = lsti->next;
		lst = NULL;
	}
	//	lstibegi = ft_lst_sort2(lstibegi);
	//	lstibegi = ft_lst_sort(lstibegi, decreasing_time);
	lsti = lstibegi;
	while (lsti)
	{
		ft_putstr("\n");
		ft_putstr(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
		ft_putstr(":\n");
		if(stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb) == 0)
		{
			if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRGRP))
				lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			if(lst)
				lstj = ft_printlist10(lst);
			else if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) == 0 || (sb.st_mode & S_IRGRP) == 0)
			{
				ft_putstr_fd("ls: ", 2);
				opendir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				perror(((t_rep*)(lsti->content))->name);
			}
		}
		lsti = lsti->next;
		lst = NULL;
	}
}
