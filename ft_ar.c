/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:45:07 by syusof            #+#    #+#             */
/*   Updated: 2016/11/02 10:43:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ar(char *s, t_lsto *lstcmd,t_ind *ind)
{

	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;
	char *s1;

	s1 = NULL;
	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist2(lst);
	lstibegi = lsti;
	while (lsti)
	{
		s1 = ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name);
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			if(stat(s1,&sb) == 0)
			{
				if(ft_isdir(s1) && (sb.st_mode & S_IRGRP))
					lst = ft_getreplist4(s1);
				if(lst && ft_isdir(s1) && (sb.st_mode & S_IRGRP))
				{
					lstj = ft_printlist3(lst);
					lsti = lst_addo_down(lsti,lstj);
				}
			}
		}
		free(s1);
		s1 = NULL;
		lsti = lsti->next;
		lst = NULL;
	}
	lstibegi = ft_lst_sort(lstibegi, croissant_pathname);
	lsti = lstibegi;
	while (lsti)
	{
		s1 = ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name);
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			ft_putstr("\n");
			ft_putstr(s1);
			ft_putstr(":\n");
			if(stat(s1,&sb) == 0)
			{
				if(ft_isdir(s1) && (sb.st_mode & S_IRGRP))
					lst = ft_getreplist4(s1);
				if(lst)
					lstj = ft_printlist2(lst);
				else if(ft_isdir(s1) == 0 || (sb.st_mode & S_IRGRP) == 0)
				{
					ft_putstr_fd("ls: ", 2);
					opendir(s1);
					perror(((t_rep*)(lsti->content))->name);
				}
			}
		}
		free(s1);
		s1 = NULL;
		lsti = lsti->next;
		lst = NULL;
	}
}
