/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl22.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:57:34 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 20:15:16 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl_p6(t_lsto *lst1, t_loption loption, struct stat sb)
{
	char		*linkname;
	ssize_t		r;

	linkname = NULL;
	ft_putstr(" -> ");
	if (loption.indrdev)
	{
		linkname = (char*)malloc(sb.st_blksize + 1);
		r = readlink(ft_makepath(((t_rep*)lst1->content)->path,
					((t_rep*)lst1->content)->name), linkname, sb.st_blksize);
		if (linkname)
			ft_wl_p6_p1(&linkname, r);
	}
	else
	{
		linkname = (char*)malloc(sb.st_size + 1);
		r = readlink(ft_makepath(((t_rep*)lst1->content)->path,
					((t_rep*)lst1->content)->name), linkname, sb.st_blksize);
		if (linkname)
			ft_wl_p6_p1(&linkname, r);
	}
}

void	ft_wl_p6_p1(char **linkname, ssize_t r)
{
	(*linkname)[r] = 0;
	ft_putstr(*linkname);
}
