/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:30 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 12:33:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int croissant(t_lsto *lsta)
{
		return (ft_strcmp(((t_rep*)(lsta)->content)->name,((t_rep*)((lsta)->next)->content)->name) <= 0);
}

int croissant_char(t_lsto *lsta)
{
		return (ft_strcmp(lsta->content,(lsta->next)->content) <= 0);
}

int decreasing(t_lsto *lsta)
{
	return (ft_strcmp(((t_rep*)(lsta)->content)->name,((t_rep*)((lsta)->next)->content)->name) > 0);
}

int decreasing_char(t_lsto *lsta)
{
	return (ft_strcmp(lsta->content,(lsta->next)->content) > 0);
}

int decreasing_time(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	ft_mem1(&s1, &s2, lsta);
	if(lstat(s1, &sa) == 0 && lstat(s2, &sb) == 0 && sa.st_mtime >= sb.st_mtime)
	{
		if (sa.st_mtime > sb.st_mtime)
			return (1);
		if (sa.st_mtime == sb.st_mtime && sa.st_mtimespec.tv_nsec >= sb.st_mtimespec.tv_nsec)
		{
			if (sa.st_mtimespec.tv_nsec > sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec && ft_strcmp(s1,s2) <= 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}
