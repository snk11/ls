/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:37:44 by syusof            #+#    #+#             */
/*   Updated: 2017/02/07 20:49:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width2(t_lsto *lst1, t_loption *loption)
{
	struct stat		sb;
	time_t			curtime;
	ssize_t			xattr;
	acl_t			acl;
	char			*s;

	acl = NULL;
	xattr = listxattr(s, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(s, ACL_TYPE_EXTENDED);
	curtime = time(NULL);
	if (lst1)
	{
		s = ((t_rep*)(lst1->content))->name;
		if (lstat(s, &sb) == 0)
		{
			if (ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
				loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
			ft_width_p1(loption, sb);
			ft_width_p2(loption, sb, curtime);
		}
		if (xattr > 0 || acl != NULL)
			loption->xattracl = 1;
	}
}
