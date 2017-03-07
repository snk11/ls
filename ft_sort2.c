/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:00:35 by syusof            #+#    #+#             */
/*   Updated: 2017/03/08 00:07:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		croissant_time(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0)
	{
		if (sa.st_mtime <= sb.st_mtime)
		{
			if (sa.st_mtime < sb.st_mtime)
				return (1);
			if (croissant_time_p1(sa, sb))
				return (croissant_time_p2(sa, sb, s1, s2));
			else
				return (0);
		}
		return (0);
	}
	return (1);
}

int		croissant_time_p1(struct stat sa, struct stat sb)
{
	if (sa.st_mtime == sb.st_mtime
			&& sa.st_mtimespec.tv_nsec <= sb.st_mtimespec.tv_nsec)
		return (1);
	return (0);
}

int		croissant_time_p2(struct stat sa, struct stat sb, char *s1, char *s2)
{
	if (sa.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
		return (1);
	else if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
			&& ft_strcmp(s1, s2) >= 0)
		return (1);
	else
		return (0);
}

int		croissant_time_char(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0)
	{
		if (sa.st_mtime <= sb.st_mtime)
		{
			if (sa.st_mtime < sb.st_mtime)
				return (1);
			if (croissant_time_p1(sa, sb))
				return (croissant_time_p2(sa, sb, s1, s2));
			else
				return (0);
		}
		return (0);
	}
	return (1);
}

int		decreasing_time_char(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1_char(&s1, &s2, lsta);
//			printf("name %s\n", s1);
//			printf("name %s\n", s2);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0)
	{
//			printf("%s = %ld\n", s1,sa.st_mtime);
//			printf("%s = %ld\n", s2,sb.st_mtime);
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
