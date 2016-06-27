/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlarreversedir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:24:45 by syusof            #+#    #+#             */
/*   Updated: 2016/06/27 15:29:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlarreversedir(char *s,t_ind *ind)
{
	struct stat		sb;
	t_lst			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;

	//if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist4(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	if (ind->indfirst > 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	lsti = ft_printlist28(lst);
	lstibegi = lsti;
	while (lsti)
	{
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
			if((sb.st_mode & S_IRUSR))
				lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			if(lst && (sb.st_mode & S_IRUSR))
			{
				lstj = ft_printlist19(lst);
				lsti = lst_addo_between(lsti,lstj);
			}
		}
		lsti = lsti->next;
		lst = NULL;
	}
	lsti = lstibegi;
	while (lsti)
	{
		if (ft_strcmp((((t_rep*)(lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(lsti)->content)->name), "..") != 0)
		{
			ft_putstr("\n");
			ft_putstr(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			ft_putstr(":\n");
			stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
			if((sb.st_mode & S_IRUSR))
				lst = ft_getreplist4(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			if(lst)
				lstj = ft_printlist28(lst);
			else if ((sb.st_mode & S_IRUSR) == 0)
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
