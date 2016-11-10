/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:44:58 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 16:26:31 by syusof           ###   ########.fr       */
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
	uid = NULL;
	gid = NULL;
		{
			if (lstat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb) == 0)
			{
				if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
					loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
				if(sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
				{
						if(ft_strlen(uid->pw_name) > loption->uname)
							loption->uname = ft_strlen(uid->pw_name);
				}
				else if(!(sb.st_uid))
				{
					if(ft_strlen("root") > loption->uname)
						loption->uname = 4;
				}
				if(sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
				{
						if(ft_strlen(gid->gr_name) > loption->gname)
							loption->gname = ft_strlen(gid->gr_name);
				}
				else if(!(sb.st_gid))
				{
					if(ft_strlen("wheel") > loption->gname)
						loption->gname = 5;
				}
				if(ft_strlen(ft_lldtoa(sb.st_size)) > loption->fsize)
					loption->fsize = ft_strlen(ft_lldtoa(sb.st_size));
				if(curtime - sb.st_mtime > 15778458)
					loption->year = ft_strlen(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
				else if(curtime - sb.st_mtime < 0)
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
	struct passwd	*uid;
	struct group	*gid;

	while (lst1)
	{
			if(lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
			{
				uid = getpwuid(sb.st_uid);
				gid = getgrgid(sb.st_gid);
				if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
					loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
				if(sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
				{
						if(ft_strlen(uid->pw_name) > loption->uname)
							loption->uname = ft_strlen(uid->pw_name);
				}
				else if(!(sb.st_uid))
				{
					if(ft_strlen("root") > loption->uname)
						loption->uname = 4;
				}
				if(sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
				{
						if(ft_strlen(gid->gr_name) > loption->gname)
							loption->gname = ft_strlen(gid->gr_name);
				}
				else if(!(sb.st_gid))
				{
					if(ft_strlen("wheel") > loption->gname)
						loption->gname = 5;
				}
				if(ft_strlen(ft_lldtoa(sb.st_size)) > loption->fsize)
					loption->fsize = ft_strlen(ft_lldtoa(sb.st_size));
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

