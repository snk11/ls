/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:30 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 16:19:48 by syusof           ###   ########.fr       */
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

	s1 = ft_memmove2(ft_makepath(((t_rep*)(lsta->content))->path,((t_rep*)(lsta->content))->name));
	s2 = ft_memmove2(ft_makepath(((t_rep*)((lsta->next)->content))->path,((t_rep*)((lsta->next)->content))->name));
	lstat(s1, &sa);
	lstat(s2, &sb);
	if (sa.st_mtime >= sb.st_mtime)
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

int croissant_time(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;


	s1 = ft_memmove2(ft_makepath(((t_rep*)(lsta->content))->path,((t_rep*)(lsta->content))->name));
	s2 = ft_memmove2(ft_makepath(((t_rep*)((lsta->next)->content))->path,((t_rep*)((lsta->next)->content))->name));
	lstat(s1, &sa);
	lstat(s2, &sb);
	if (sa.st_mtime <= sb.st_mtime)
	{
		if (sa.st_mtime < sb.st_mtime)
			return (1);
		if (sa.st_mtime == sb.st_mtime && sa.st_mtimespec.tv_nsec <= sb.st_mtimespec.tv_nsec)
		{
			if (sa.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec && ft_strcmp(s1,s2) >= 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int croissant_time_char(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	s1 = ft_memmove2(lsta->content);
	s2 = ft_memmove2((lsta->next)->content);
	lstat(s1, &sa);
	lstat(s2, &sb);
	if (sa.st_mtime <= sb.st_mtime)
	{
 		if (sa.st_mtime < sb.st_mtime)
			return (1);
		if (sa.st_mtime == sb.st_mtime && sa.st_mtimespec.tv_nsec <= sb.st_mtimespec.tv_nsec)
		{
			if (sa.st_mtimespec.tv_nsec < sb.st_mtimespec.tv_nsec)
				return (1);
			if (sa.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec && ft_strcmp(s1,s2) >= 0)
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int decreasing_time_char(t_lsto *lsta)
{
	struct stat		sa;
	struct stat		sb;
	char			*s1;
	char			*s2;

	s1 = ft_memmove2(lsta->content);
	s2 = ft_memmove2((lsta->next)->content);
	lstat(s1, &sa);
	lstat(s2, &sb);
	if (sa.st_mtime >= sb.st_mtime)
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

int croissant_pathname(t_lsto *lsti)
{
		return (ft_strcmp(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti)->content)->name),ft_makepath(((t_rep*)((lsti->next)->content))->path,((t_rep*)((lsti->next)->content))->name)) <= 0);
}

t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*))
{
	t_lsto *lstmp1;
	t_lsto *lstmp2;
	t_lsto *lstbegi;
	int		ind;
	long long	count;

	count = 0;
	lstbegi = lst;
	lstmp1 = NULL;
	lstmp2 = NULL;
	ind = 1;
	if (lst == NULL)
		ind = 0;
	while (ind != 0)
	{
		ind = 0;
		lst = lstbegi;
		lstmp1 = lst;
		if (lstbegi->next)
		{
			if ((cmp)(lstbegi) == 0)
			{
				lstmp2 = (lstbegi->next)->next;
				lstmp1 = lstbegi->next;
				(lstbegi->next)->next = lstbegi;
				lstbegi->next = lstmp2;
				lstbegi = lstmp1;
				ind = 1;
			}
			lst = lstbegi;
			lst = lst->next;
		}
		while(lst->next != NULL)
		{
			if ((cmp)(lst) == 0)
			{
				lstmp1->next = lst->next;
				lstmp2 = (lst->next)->next;
				(lst->next)->next = lst;
				lst->next = lstmp2;
				ind = 1;
			}
			lst = lstmp1->next;
			lstmp1 = lst;
			if (lst->next)
				lst = lst->next;
			count++;
		}
	}
	return (lstbegi);
}
