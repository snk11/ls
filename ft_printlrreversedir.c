/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlrreversedir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:03:45 by syusof            #+#    #+#             */
/*   Updated: 2016/10/31 12:45:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlrreversedir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;
	char			*s1;

	s1 = NULL;
	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist18(lst);
	lstibegi = lsti;
	while (lsti)
	{
		s1 = ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name);
		stat(s1,&sb);
		if((sb.st_mode & S_IRGRP))
			lst = ft_getreplist(s1);
		if(lst && (sb.st_mode & S_IRGRP))
		{
			lstj = ft_printlist19(lst);
			lsti = lst_addo_between(lsti,lstj);
		}
		free(s1);
		s1 = NULL;
		lsti = lsti->next;
		lst = NULL;
	}
	lsti = lstibegi;
	while (lsti)
	{
		s1 = ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name);
		ft_putstr("\n");
		ft_putstr(s1);
		ft_putstr(":\n");
		stat(s1,&sb);
		if((sb.st_mode & S_IRGRP))
			lst = ft_getreplist(s1);
		if(lst)
			lstj = ft_printlist18(lst);
		else if ((sb.st_mode & S_IRGRP) == 0)
		{
			ft_putstr_fd("ls: ", 2);
			opendir(s1);
			perror(((t_rep*)(lsti->content))->name);
		}
		free(s1);
		s1 = NULL;
		lsti = lsti->next;
		lst = NULL;
	}
}
