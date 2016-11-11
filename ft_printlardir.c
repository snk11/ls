/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlardir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:03:28 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 15:19:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlardir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist16(lst);
	lstibegi = lsti;
	while (lsti)
	{
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			if(stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb) == 0)
			{
				if((sb.st_mode & S_IRGRP))
					lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				if(lst && (sb.st_mode & S_IRGRP))
				{
					lstj = ft_printlist3(lst);
					lsti = lst_addo_down(lsti,lstj);
				}
			}
		}
		lsti = lsti->next;
		lst = NULL;
	}
	lstibegi = ft_lst_sort(lstibegi,croissant_pathname);
	lsti = lstibegi;
	while (lsti)
	{
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			ft_putstr("\n");
			ft_putstr(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			ft_putstr(":\n");
			if(stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb) == 0)
			{
				if((sb.st_mode & S_IRGRP))
					lst = ft_getreplist4(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				if(lst)
					lstj = ft_printlist16(lst);
				else if ((sb.st_mode & S_IRGRP) == 0)
				{
					ft_putstr_fd("ls: ", 2);
					opendir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
					perror(((t_rep*)(lsti->content))->name);
				}
			}
		}
		lsti = lsti->next;
		lst = NULL;
	}
}
