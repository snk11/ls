/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:39:04 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 15:14:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl2(t_lsto *lst1, t_loption loption)
{
	struct stat		sb;
	time_t			curtime;
	char *s;

	s = ((t_rep*)(lst1->content))->name;
	curtime = time(NULL);
	if (lst1)
	{
		if (lstat(s, &sb) == 0)
		{
			ft_wl_p(s, loption, sb, curtime);
			if (curtime - sb.st_mtime > 15778458)
				ft_wl_p3(loption, sb, curtime);
			else if (curtime - sb.st_mtime < 0)
				ft_wl_p4(loption, sb, curtime);
			else
				ft_wl_p5(loption, sb, curtime);
			ft_putstr(((t_rep*)lst1->content)->name);
			if (ft_islnk(s))
				ft_wl_p6(lst1, loption, sb, curtime);
			ft_putstr("\n");
		}
//		lst1 = lst1->next;
	}
	/*
	struct stat		sb;
	time_t			curtime;

	curtime = time(NULL);
	while (lst1)
	{
		if (lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
		{
			ft_wl_p(lst1, loption, sb, curtime);
			if (curtime - sb.st_mtime > 15778458)
				ft_wl_p3(loption, sb, curtime);
			else if (curtime - sb.st_mtime < 0)
				ft_wl_p4(loption, sb, curtime);
			else
				ft_wl_p5(loption, sb, curtime);
			ft_putstr(((t_rep*)lst1->content)->name);
			if (ft_islnk(ft_makepath(((t_rep*)lst1->content)->path,
							((t_rep*)lst1->content)->name)))
				ft_wl_p6(lst1, loption, sb, curtime);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	*/
}

void	ft_wl_p6(t_lsto *lst1, t_loption loption, struct stat sb,
		time_t curtime)
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
		{
			linkname[r] = 0;
			ft_putstr(linkname);
		}
	}
	else
	{
		linkname = (char*)malloc(sb.st_size + 1);
		r = readlink(ft_makepath(((t_rep*)lst1->content)->path,
					((t_rep*)lst1->content)->name), linkname, sb.st_size);
		if (linkname)
		{
			linkname[r] = 0;
			ft_putstr(linkname);
		}
	}
}
