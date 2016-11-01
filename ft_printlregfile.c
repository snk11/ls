/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlregfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:31:45 by syusof            #+#    #+#             */
/*   Updated: 2016/11/01 01:49:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlregfile(t_lsto *lst1)
{
	struct stat		sb;
	t_loption	loption;
	ssize_t		r;
	t_rep	*e;
	t_lsto	*lstmp;

	lstmp = NULL;
	//			lstat(ft_makepath("./",(char*)(lstmp1->content)), &sb);
	ft_init2(&loption);

		 (e = (t_rep*)malloc(sizeof(t_rep)));
//		e->name = pdirent1->d_name;
//		e->path = rep;

		{
			lstmp = ft_create_lsto(e);
			((t_rep*)(lstmp->content))->name = (char*)lst1->content;
			((t_rep*)(lstmp->content))->path = ".";
		}

	ft_width(lstmp,&loption);
	ft_wl(lstmp,loption);
//	ft_wl2(lstmp,loption);


		/*
		int		l;
	time_t		curtime;
	int	i;

	l = 0;
	curtime = time(NULL);
			lstat(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name));
			ft_putstr("  ");
			ft_putwidth(ft_ustoa(sb.st_nlink),loption.link);
			ft_putstr(" ");
			ft_putwidth(getpwuid(sb.st_uid)->pw_name,loption.uname);
			ft_putstr("  ");
			ft_putwidth(getgrgid(sb.st_gid)->gr_name,loption.gname);
			ft_putstr("  ");
			ft_putwidth(ft_lldtoa(sb.st_size),loption.fsize);
			ft_putstr(" ");
			ft_putmonth((localtime(&(sb.st_mtime)))->tm_mon);
			ft_putstr(" ");
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
				if(loption.year > 4)
					ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				else
				{
					i = 4 - loption.year;
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
				ft_putstr(" ");
				ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday),loption.day);
				ft_putstr(" ");
				ft_putstr(" ");
				ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				ft_putstr(" ");
			}
			else
			{
				if (loption.year > 4)
				{
					i = loption.year - 4;
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
			ft_putstr(((t_rep*)((lstmp))->content)->name);
			linkname = malloc(sb.st_size + 1);
			r = readlink(ft_makepath(((t_rep*)lstmp->content)->path,((t_rep*)lstmp->content)->name),linkname,sb.st_size + 1);
			if(ft_islnk(ft_makepath(((t_rep*)lstmp->content)->path,((t_rep*)lstmp->content)->name )))
			{
				ft_putstr(" -> ");
				//readlink("f",linkname,PATH_MAX);
//				readlink(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name),linkname,);
				if(linkname)
					ft_putstr(linkname);
			}
			ft_putstr("\n");
			*/
}
