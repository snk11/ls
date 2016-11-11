/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:21:34 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 15:02:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_function_r(t_lsto **lsti, t_lsto *lst, t_lsto* (*f1)(char *), t_lsto* (*f2)(t_lsto *))
{
	char	*s1;
	t_lsto	*lstj;
	struct stat		sb;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,((t_rep*)((*lsti)->content))->name);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		if(stat(s1,&sb) == 0)
		{
			if(ft_isdir(s1) && (sb.st_mode & S_IRGRP))
				lst = f1(s1);
			if(lst && ft_isdir(s1) && (sb.st_mode & S_IRGRP))
			{
				lstj = f2(lst);
				*lsti = lst_addo_down(*lsti,lstj);
			}
		}
	}
	free(s1);
	s1 = NULL;
	*lsti = (*lsti)->next;
	lst = NULL;
}


void	ft_function_r2(t_lsto **lsti, t_lsto *lst, t_lsto* (*f1)(char *), t_lsto* (*f2)(t_lsto *))
{
	char	*s1;
	t_lsto	*lstj;
	struct stat		sb;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,((t_rep*)((*lsti)->content))->name);
		if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0 && ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
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
					perror(((t_rep*)((*lsti)->content))->name);
				}
			}
		}
		free(s1);
		s1 = NULL;
		(*lsti) = (*lsti)->next;
		lst = NULL;
}
