/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:45:09 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 16:32:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_r(char *s, t_ind *ind)
{

	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;

	//if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist(s);
//	if (ind->indfirst > 1)
	if (ind->indtotal != 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	lsti = ft_printlist2(lst);
	lstibegi = lsti;
	while (lsti)
	{
		stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
//		if((sb.st_mode & S_IRUSR))
		if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRUSR))
			lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
		if(lst && ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRUSR))
		{
			lstj = ft_printlist3(lst);
			lsti = lst_addo_down(lsti,lstj);
		}
		lsti = lsti->next;
		lst = NULL;
	}
//	lstibegi = ft_lst_sort2(lstibegi);
	lstibegi = ft_lst_sort(lstibegi,croissant_pathname);
	lsti = lstibegi;
	while (lsti)
	{
		ft_putstr("\n");
		ft_putstr(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
		ft_putstr(":\n");
		stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
		if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) && (sb.st_mode & S_IRUSR))
			lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
		if(lst)
			lstj = ft_printlist2(lst);
		else if(ft_isdir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name)) == 0 || (sb.st_mode & S_IRUSR) == 0)
		{
			ft_putstr_fd("ls: ", 2);
			opendir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
			perror(((t_rep*)(lsti->content))->name);
		}
		lsti = lsti->next;
		lst = NULL;
	}
}
