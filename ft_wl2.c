/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:39:04 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 10:39:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl2(t_lsto *lst1,t_loption loption)
{
	struct stat		sb;
	char	*linkname;
	int		l;
	ssize_t		r;
	time_t		curtime;
	int	i;
	struct passwd *uid;
	struct group	*gid;

	l = 0;
	curtime = time(NULL);
	linkname = NULL;
	while (lst1)
	{
		if (lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
		{
			uid = getpwuid(sb.st_uid);
			gid = getgrgid(sb.st_gid);
			ft_print_permission(((t_rep*)(lst1->content))->name);
			ft_putstr("  ");
			ft_putwidth(ft_ustoa(sb.st_nlink),loption.link);
			ft_putstr(" ");
			if(sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
			{
				ft_putwidth(uid->pw_name,loption.uname);
				ft_putstr("  ");
			}
			else if(!(sb.st_uid))
			{
				ft_putwidth("root",loption.uname);
				ft_putstr("  ");
			}
			if(sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
			{
				ft_putwidth(gid->gr_name,loption.gname);
				ft_putstr("  ");
			}
			else if(!(sb.st_gid))
			{
				ft_putwidth("wheel",loption.gname);
				ft_putstr("  ");
			}
			ft_putwidth(ft_lldtoa(sb.st_size),loption.fsize);
			ft_putstr(" ");
			ft_putmonth((localtime(&(sb.st_mtime)))->tm_mon);
			ft_putstr(" ");
			if(curtime - sb.st_mtime >= 0)
			{
				ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday),loption.day);
				ft_putstr(" ");
			}
			if(curtime - sb.st_mtime > 15778458)
			{
				if(loption.year > 5)
					ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				else
				{
					i = 5 - loption.year;
					while (i > 0)
					{
						ft_putstr(" ");
						i--;
					}
					ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				}
				ft_putstr(" ");
			}
			else if(curtime - sb.st_mtime < 0)
			{
				ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday),loption.day);
				ft_putstr(" ");
				ft_putstr(" ");
				ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				ft_putstr(" ");
			}
			else
			{
				if (loption.year > 5)
				{
					i = loption.year - 5;
					while(i > 0)
					{
						ft_putstr(" ");
						i--;
					}
					ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour),loption.hour);
					ft_putstr(":");
					ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_min),loption.minute);
				}
				else
				{
					ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour),loption.hour);
					ft_putstr(":");
					ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_min),loption.minute);
				}
				ft_putstr(" ");
			}
			ft_putstr(((t_rep*)lst1->content)->name);
			if(ft_islnk(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name )))
			{
				ft_putstr(" -> ");
				linkname = (char*)malloc(sb.st_size + 1);
				r = readlink(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name),linkname,sb.st_size);

				if(linkname)
				{
					linkname[r] = 0;
					ft_putstr(linkname);
				}
			}
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}

}
