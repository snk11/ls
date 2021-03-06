/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:21:34 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 14:07:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_function_rl(t_lsto **lsti, t_lsto *lst,
		t_lsto *(*f1)(char*), t_lsto *(*f2)(t_lsto*))
{
	char			*s1;
	t_lsto			*lstj;
	struct stat		sb;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,
			((t_rep*)((*lsti)->content))->name);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0
			&& ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		if (stat(s1, &sb) == 0)
		{
			if (sb.st_mode & S_IRWXU)
				lst = f1(s1);
			if (lst && sb.st_mode & S_IRWXU)
			{
				lstj = f2(lst);
				*lsti = lst_addo_between(*lsti, lstj);
			}
		}
	}
	*lsti = (*lsti)->next;
}

void	ft_function_r4(t_lsto **lsti, t_lsto *lst,
		t_lsto *(*f1)(char *), t_lsto *(*f2)(t_lsto *))
{
	t_lsto			*lstj;
	char			*s1;
	struct stat		sb;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,
			((t_rep*)((*lsti)->content))->name);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0
			&& ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		ft_function_r4_p1(s1);
		if (stat(s1, &sb) == 0)
		{
			if (sb.st_mode & S_IRWXU)
				lst = f1(s1);
			if (lst && sb.st_mode & S_IRWXU)
				lstj = f2(lst);
			else if (!opendir(s1))
				ft_function_r4_p2(s1, lsti);
		}
	}
	(*lsti) = (*lsti)->next;
}

void	ft_function_r4_p1(char *s1)
{
	ft_putstr("\n");
	ft_putstr(s1);
	ft_putstr(":\n");
}

void	ft_function_r4_p2(char *s1, t_lsto **lsti)
{
	ft_putstr_fd("ls: ", 2);
	opendir(s1);
	perror(((t_rep*)((*lsti)->content))->name);
}
