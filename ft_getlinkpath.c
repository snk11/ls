/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinkpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:39:29 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 17:49:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getlinkpath(char *s1)
{
	char		*linkname;
	ssize_t		r;
	struct stat	sb;

	linkname = NULL;
	if (!(lstat(s1, &sb) == 0))
		return (0);
	linkname = (char*)malloc(sb.st_size + 1);
	r = readlink(s1, linkname, sb.st_size);
	if (linkname)
	{
		linkname[r] = 0;
	}
	return (linkname);
}
