/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:39:04 by syusof            #+#    #+#             */
/*   Updated: 2017/02/02 13:33:10 by syusof           ###   ########.fr       */
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
			ft_wl_pmod(s, loption, sb, curtime);
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

void	ft_wl_pmod(char *s, t_loption loption, struct stat sb, time_t curtime)
{
	ft_wl_p0(s, loption, sb);
	ft_wl_p12(loption, sb);
	ft_wl_p22(loption, sb, curtime);
}

void	ft_wl_p12(t_loption loption, struct stat sb)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = NULL;
	gid = NULL;
	if (sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
	{
		ft_putwidth3(uid->pw_name, loption.uname);
		ft_putstr("  ");
	}
	else if (!(sb.st_uid))
	{
		ft_putwidth3("root", loption.uname);
		ft_putstr("  ");
	}
	if (sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
	{
		ft_putwidth3(gid->gr_name, loption.gname);
		ft_putstr("  ");
	}
	else if (!(sb.st_gid))
	{
		ft_putwidth3("wheel", loption.gname);
		ft_putstr("   ");
	}
}

void	ft_wl_p22(t_loption loption, struct stat sb, time_t curtime)
{
	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		ft_putwidth(ft_itoa(major(sb.st_rdev)), loption.frdevmaj);
		ft_putstr(",   ");
	}
	else if (loption.indrdev)
	{
		ft_putwidth("",loption.frdevmaj);
		ft_putstr("   ");
	}
	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		ft_putwidth(ft_itoa(minor(sb.st_rdev)), loption.frdevmin);
		ft_putstr(" ");
	}
	else if (loption.indrdev)
	{
		ft_putwidth(ft_lldtoa(sb.st_size), loption.frdevmin);
		ft_putstr("  ");
	}
	else
	{
		ft_putwidth(ft_lldtoa(sb.st_size), loption.fsize);
		ft_putstr(" ");
	}
	ft_putmonth((ctime(&(sb.st_mtime))));
	ft_putstr(" ");
	if (curtime - sb.st_mtime >= 0)
	{
		ft_putwidth(ft_getday_str(ctime(&(sb.st_mtime))), loption.day);
		ft_putstr(" ");
	}
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
