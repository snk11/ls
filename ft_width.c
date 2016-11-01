/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:44:58 by syusof            #+#    #+#             */
/*   Updated: 2016/11/01 19:10:55 by syusof           ###   ########.fr       */
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
		}
		lst1 = lst1->next;
	}

}


void	ft_width2(t_lsto *lst1,t_loption *loption)
{
	struct stat		sb;
	time_t		curtime;

	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			lstat(((t_rep*)(lst1->content))->name, &sb);
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
		}
		lst1 = lst1->next;
	}

}

