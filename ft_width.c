/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:44:58 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 13:30:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width(t_lsto *lst1,t_loption *loption)
{
	struct stat		sb;
	time_t		curtime;
	struct passwd	*uid;
	struct group	*gid;

	uid = NULL;
	gid = NULL;
	while (lst1)
	{
//		if(ft_checkokfile(((t_rep*)(lst1->content))->name) == 1)
//			ft_width2(lst1,loption);
//		else
	uid = NULL;
	gid = NULL;
		{
			if (lstat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb) == 0)
			{
					//uid = getpwuid(sb.st_uid);
					//gid = getgrgid(sb.st_gid);
				if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
					loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
				if(sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
				{
//					if(uid)
					{
						if(ft_strlen(uid->pw_name) > loption->uname)
							loption->uname = ft_strlen(uid->pw_name);
					}
				}
				if(sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
				{
//					if(gid)
					{
						if(ft_strlen(gid->gr_name) > loption->gname)
							loption->gname = ft_strlen(gid->gr_name);
					}
				}
				if(ft_strlen(ft_lldtoa(sb.st_size)) > loption->fsize)
					loption->fsize = ft_strlen(ft_lldtoa(sb.st_size));
				//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mon)) > loption->month)
				//				loption->month = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mon));
				//			if(ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday)) > loption->day)
				//				loption->day = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday));
				if(curtime - sb.st_mtime > 15778458)
				{
					loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				}
				else if(curtime - sb.st_mtime < 0)
				{
					loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));

				}
			}
		}
		lst1 = lst1->next;
	}

}


void	ft_width2(t_lsto *lst1,t_loption *loption)
{
	struct stat		sb;
	time_t		curtime;
	struct passwd	*uid;
	struct group	*gid;

	while (lst1)
	{
//		if(ft_checkokfile(((t_rep*)(lst1->content))->name) == 0)
//			ft_width(lst1,loption);
//		else
		{
			if(lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
			{
				uid = getpwuid(sb.st_uid);
				gid = getgrgid(sb.st_gid);
				if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
					loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
				if((uid = getpwuid(sb.st_uid)) != NULL)
				{
				if(ft_strlen(uid->pw_name) > loption->uname)
					loption->uname = ft_strlen(uid->pw_name);
				}
				if((gid = getgrgid(sb.st_gid)) != NULL)
				{
				if(ft_strlen(gid->gr_name) > loption->gname)
					loption->gname = ft_strlen(gid->gr_name);
				}
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
		}
		lst1 = lst1->next;
	}

}

