/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:27:40 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 18:13:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl(t_lsto *lst1, t_loption loption)
{
	struct stat		sb;
	time_t			curtime;
	char			*s;

	curtime = time(NULL);
	while (lst1)
	{
	s = ft_makepath(((t_rep*)(lst1->content))->path, ((t_rep*)(lst1->content))->name);
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
		lst1 = lst1->next;
	}
}

void	ft_wl_p(char *s, t_loption loption, struct stat sb, time_t curtime)
{
	ft_wl_p0(s, loption, sb);
	ft_wl_p1(loption, sb);
	ft_wl_p2(loption, sb, curtime);
}

void	ft_wl_p0(char *s, t_loption loption, struct stat sb)
{
	ft_print_permission(s, loption);
	ft_putwidth(ft_ustoa(sb.st_nlink), loption.link);
	ft_putstr(" ");
}

void	ft_wl_p1(t_loption loption, struct stat sb)
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
		ft_putstr("  ");
	}
}

void	ft_wl_p2(t_loption loption, struct stat sb, time_t curtime)
{
	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		ft_putwidth(ft_itoa(major(sb.st_rdev)), loption.frdevmaj);
		ft_putstr(",  ");
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
	if (curtime - sb.st_mtime >= 0)
	{
		ft_putwidth(ft_getday_str(ctime(&(sb.st_mtime))), loption.day);
		ft_putstr(" ");
	}
}
