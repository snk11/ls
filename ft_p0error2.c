/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:29:22 by syusof            #+#    #+#             */
/*   Updated: 2017/03/04 13:37:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error_p1(char *s, t_ind *ind)
{
	int		inderror;

	inderror = 0;
	ind->ind1 = 0;
	if (!opendir(s))
	{
		inderror = 1;
	}
	if (inderror == 1 && !ft_isreg(s)
			&& !ft_islnk(s))
		ft_p0error_p1_p1(s, ind);
}

void	ft_p0error_p1_p1(char *s, t_ind *ind)
{
	struct stat		sb;

	if (lstat(s, &sb) == 0 && !((sb.st_mode & S_IRGRP)
				&& (sb.st_mode & S_IROTH)))
	{
		/*
		ft_putstr_fd("ls: ", 2);
		if (ft_check_slash_end_case(s) == 0)
			ft_putstr_fd(ft_getname_without_slash(s), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		*/
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	ft_putstr_fd("\n", 2);
	ind->inderror = 1;
}
/*
void	ft_p0error_p1_p2(t_lsto *lst1, t_ind *ind)
{
	char	*s1;

	s1 = ft_memmove2((char*)(lst1->content));
	if (ind->ind1 == 0 && !ft_isreg(s1) && !ft_islnk(s1))
	{
		if ((!opendir((char*)(lst1->content))
					&& (((char*)(lst1->content))[0] != '-'
						|| ind->indoption == 0
						|| ft_strcmp((char*)lst1->content, "--") == 0)))
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd((char*)(lst1->content), 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
		}
		ind->inderror = 1;
	}
}
*/
