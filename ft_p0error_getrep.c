/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error_getrep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:01:48 by syusof            #+#    #+#             */
/*   Updated: 2017/03/14 16:08:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error_getrep(char *s)
{
	int		inderror;
	t_lsto	*lstmp;

	inderror = 0;
	if (!opendir(s))
	{
		inderror = 1;
	}
	if (inderror == 1 && !ft_isreg(s)
			&& !ft_islnk(s))
		ft_p0error_getrep_p1(s);
}

void	ft_p0error_getrep_p1(char *s)
{
	struct stat		sb;


	if (lstat(s, &sb) == 0 && !((sb.st_mode & S_IRGRP)
				&& (sb.st_mode & S_IROTH)))
	{
		ft_putstr_fd("ls: ", 2);
		if (ft_check_slash_end_case(s) == 0)
			ft_putstr_fd(ft_getname_without_slash(s), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	ft_putstr_fd("\n", 2);
}
