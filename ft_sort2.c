/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:00:35 by syusof            #+#    #+#             */
/*   Updated: 2017/02/14 17:34:45 by syusof           ###   ########.fr       */
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
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0
			&& sa.st_mtime <= sb.st_mtime)
	{
		if (sa.st_mtime < sb.st_mtime)
			return (1);
		if (croissant_time_p1(sa, sb))
		{
			if (sa.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
					&& ft_strcmp(s1, s2) >= 0)
				return (1);
			else
				return (0);
		}
		else
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

int		croissant_time_char(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0
			&& sa.st_mtime <= sb.st_mtime)
	{
		if (sa.st_mtime < sb.st_mtime)
			return (1);
		if (croissant_time_p1(sa, sb))
		{
			if (sa.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
					&& ft_strcmp(s1, s2) >= 0)
				return (1);
			else
				return (0);
		}
		else
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
	if (lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0
			&& sa.st_mtime >= sb.st_mtime)
	{
		if (sa.st_mtime > sb.st_mtime)
			return (1);
		if (decreasing_time_p1(sa, sb))
		{
			if (sa.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec
					&& ft_strcmp(s1, s2) <= 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int		croissant_pathname(t_lsto *lsti)
{
	return (ft_strcmp(ft_makepath(((t_rep*)(lsti->content))->path,
					((t_rep*)(lsti)->content)->name),
				ft_makepath(((t_rep*)((lsti->next)->content))->path,
					((t_rep*)((lsti->next)->content))->name)) <= 0);
}
