/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:33:08 by syusof            #+#    #+#             */
/*   Updated: 2017/03/07 23:56:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			decreasing_time(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0)
	{
		if (sa.st_mtime >= sb.st_mtime)
		{
			if (sa.st_mtime > sb.st_mtime)
				return (1);
			if (decreasing_time_p1(sa, sb))
				return (decreasing_time_p2(sa, sb, s1, s2));
			else
				return (0);
		}
		return (0);
	}
	return (1);
}

int			decreasing_time_p1(struct stat sa, struct stat sb)
{
	if (sa.st_mtime == sb.st_mtime
			&& sa.st_mtimespec.tv_nsec >= sb.st_mtimespec.tv_nsec)
		return (1);
	return (0);
}

int			decreasing_time_p2(struct stat sa, struct stat sb, char *s1,
		char *s2)
{
	if (sa.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec)
		return (1);
	else if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(s1, s2) <= 0)
		return (1);
	else
		return (0);
}
