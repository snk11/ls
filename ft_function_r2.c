/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_r2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:47:28 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 17:10:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_function_r2(t_lsto **lsti, t_lsto *lst, t_lsto* (*f1)(char *), t_lsto* (*f2)(t_lsto *))
{
	char	*s1;
	t_lsto	*lstj;
	struct stat		sb;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,
			((t_rep*)((*lsti)->content))->name);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0
			&& ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		ft_function_r2_p1(s1);
		if(stat(s1,&sb) == 0)
		{
			if(ft_isdir(s1) && (sb.st_mode & S_IRGRP))
				lst = ft_getreplist4(s1);
//			if(lst)
			if(lst && (sb.st_mode & S_IRGRP))
				lstj = ft_printlist2(lst);
			else if(ft_isdir(s1) == 0 || (sb.st_mode & S_IRGRP) == 0)
			{
				ft_putstr_fd("ls: ", 2);
				opendir(s1);
				perror(((t_rep*)((*lsti)->content))->name);
			}
		}
	}
	(*lsti) = (*lsti)->next;
}

void		ft_function_r2_p1(char *s1)
{
	ft_putstr("\n");
	ft_putstr(s1);
	ft_putstr(":\n");
}


