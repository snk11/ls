/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:27:40 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 13:44:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl(t_lsto *lst1,t_loption loption)
{
	struct stat		sb;
	char	*linkname;
	int		l;
	ssize_t		r;
	time_t		curtime;
	int	i;
	struct passwd	*uid;
	struct group	*gid;

	uid = NULL;
	gid = NULL;
	l = 0;
	curtime = time(NULL);
	linkname = NULL;
	while (lst1)
	{
	uid = NULL;
	gid = NULL;
//		if(ft_checkokfile(((t_rep*)(lst1->content))->name))
//			ft_wl2(lst1,loption);
//		else
		{
			if (lstat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb) == 0)
			{
				//uid = getpwuid(sb.st_uid);
				//gid = getgrgid(sb.st_gid);
				ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
				ft_putstr("  ");
				ft_putwidth(ft_ustoa(sb.st_nlink),loption.link);
				ft_putstr(" ");
				if(sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
				{
//					if(uid)
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
//					if(gid)
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
//				if(ft_strcmp(getgrgid(sb.st_gid)->gr_name,"syusof") != 0)
					ft_putstr(" ");
//				else
//					ft_putstr("  ");

				if(curtime - sb.st_mtime >= 0)
				{
					ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday),loption.day);
					ft_putstr(" ");
				}
				//			printf("time = %ld\n",curtime);
				//			printf("time2 = %ld\n",sb.st_ctime);
				//			printf("time3 = %ld\n",curtime-sb.st_ctime);
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
					//ft_putstr(" ");
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
				//			ft_putulongnbr(sb.st_blocks);
				//			l = l + sb.st_blocks;
				//			ft_putstr(" ");
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
		}
		lst1 = lst1->next;
	}
}

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
//		if(ft_checkokfile(((t_rep*)(lst1->content))->name) == 0)
//			ft_wl(lst1,loption);
//		else
		{
			if (lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
			{
				uid = getpwuid(sb.st_uid);
				gid = getgrgid(sb.st_gid);
				ft_print_permission(((t_rep*)(lst1->content))->name);
				ft_putstr("  ");
				ft_putwidth(ft_ustoa(sb.st_nlink),loption.link);
				ft_putstr(" ");
				if((uid = getpwuid(sb.st_uid)) != NULL)
				{
				ft_putwidth(uid->pw_name,loption.uname);
				ft_putstr("  ");
				}
				if((gid = getgrgid(sb.st_gid)) != NULL)
				{
				ft_putwidth(gid->gr_name,loption.gname);
				ft_putstr("  ");
				}
				ft_putwidth(ft_lldtoa(sb.st_size),loption.fsize);
				ft_putstr(" ");
				ft_putmonth((localtime(&(sb.st_mtime)))->tm_mon);
//				if(ft_strcmp(getgrgid(sb.st_gid)->gr_name,"syusof") != 0)
					ft_putstr(" ");
//				else
//					ft_putstr("  ");

				if(curtime - sb.st_mtime >= 0)
				{
					ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday),loption.day);
					ft_putstr(" ");
				}
				//			printf("time = %ld\n",curtime);
				//			printf("time2 = %ld\n",sb.st_ctime);
				//			printf("time3 = %ld\n",curtime-sb.st_ctime);
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
				//	ft_putstr(" ");
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
				//			ft_putulongnbr(sb.st_blocks);
				//			l = l + sb.st_blocks;
				//			ft_putstr(" ");
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
		}
		lst1 = lst1->next;
	}

}
