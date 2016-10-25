/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:44:58 by syusof            #+#    #+#             */
/*   Updated: 2016/10/25 19:08:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width(t_lsto *lst1,t_loption *loption)
{
	struct stat		sb;
	time_t		curtime;

	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			lstat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
				loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
			if(ft_strlen(getpwuid(sb.st_uid)->pw_name) > loption->uname)
				loption->uname = ft_strlen(getpwuid(sb.st_uid)->pw_name);
			if(ft_strlen(getgrgid(sb.st_gid)->gr_name) > loption->gname)
				loption->gname = ft_strlen(getgrgid(sb.st_gid)->gr_name);
			if(ft_strlen(ft_lldtoa(sb.st_size)) > loption->fsize)
				loption->fsize = ft_strlen(ft_lldtoa(sb.st_size));
//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mon)) > loption->month)
//				loption->month = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mon));
			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday)) > loption->day)
				loption->day = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday));
			if(curtime - sb.st_mtime > 15778458)
			{
				loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
			}
			else if(curtime - sb.st_mtime < 0)
			{
				loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));

			}
//			else
//			{
//				loption->year = 1;
//			}
//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour)) > loption->hour)
//				loption->hour = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour));
//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_min)) > loption->minute)
//				loption->minute = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_min));
//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900)) > loption->year)
//				loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
//			ft_putulongnbr(sb.st_blocks);
//			l = l + sb.st_blocks;
//			ft_putstr(" ");
//			ft_putstr(((t_rep*)((lst1))->content)->name);
//			if(ft_islnk(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name))  )
//			{
//				ft_putstr(" -> ");
//				readlink(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name),linkname,PATH_MAX);
//				ft_putstr(linkname);
//			}
//			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}

}
