/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:44:58 by syusof            #+#    #+#             */
/*   Updated: 2017/02/13 15:00:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width(t_lsto *lst1, t_loption *loption)
{
	struct stat		sb;
	time_t			curtime;
	ssize_t			xattr;
	acl_t			acl;
	char			*s;

	acl = NULL;
	xattr = listxattr(s, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(s, ACL_TYPE_EXTENDED);
	curtime = time(NULL);
	while (lst1)
	{
		s = ft_makepath(((t_rep*)(lst1->content))->path,
				((t_rep*)(lst1->content))->name);
		if (lstat(s, &sb) == 0)
		{
			if (ft_strlen(ft_ustoa(sb.st_nlink)) > (size_t)loption->link)
				loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
			ft_width_p1(loption, sb);
			ft_width_p2(loption, sb, curtime);
		}
		if (xattr > 0 || acl != NULL)
			loption->xattracl = 1;
		lst1 = lst1->next;
	}
	if (loption->fsize > (loption->frdevmin + 1))
		loption->frdevmin = loption->fsize - 1;
	else
		loption->fsize = loption->frdevmin + 1;
}

void	ft_width_p1(t_loption *loption, struct stat sb)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = NULL;
	gid = NULL;
	if (sb.st_uid && (uid = getpwuid(sb.st_uid)) != NULL)
	{
		if (ft_strlen(uid->pw_name) > (size_t)loption->uname)
			loption->uname = ft_strlen(uid->pw_name);
	}
	else if (!(sb.st_uid))
	{
		if (ft_strlen("root") > (size_t)loption->uname)
			loption->uname = 4;
	}
	if (sb.st_gid && (gid = getgrgid(sb.st_gid)) != NULL)
	{
		if (ft_strlen(gid->gr_name) > (size_t)loption->gname)
			loption->gname = ft_strlen(gid->gr_name);
	}
	else if (!(sb.st_gid))
	{
		if (ft_strlen("wheel") > (size_t)loption->gname)
			loption->gname = 5;
	}
}

void	ft_width_p2(t_loption *loption, struct stat sb, time_t curtime)
{
	if (major(sb.st_rdev) > 0)
		loption->indrdev = 1;
	if (ft_strlen(ft_itoa(major(sb.st_rdev))) > (size_t)loption->frdevmaj)
		loption->frdevmaj = ft_strlen(ft_itoa(major(sb.st_rdev)));
	if (ft_strlen(ft_itoa(minor(sb.st_rdev))) > (size_t)loption->frdevmin)
		loption->frdevmin = ft_strlen(ft_itoa(minor(sb.st_rdev)));
	if (ft_strlen(ft_lldtoa(sb.st_size)) > (size_t)loption->fsize)
		loption->fsize = ft_strlen(ft_lldtoa(sb.st_size));
	if (curtime - sb.st_mtime > 15778458)
		loption->year = ft_strlen(ft_getyear_str(ctime(&(sb.st_mtime))));
	else if (curtime - sb.st_mtime < 0)
		loption->year = ft_strlen(ft_getyear_str(ctime(&(sb.st_mtime))));
}
