/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:21:34 by syusof            #+#    #+#             */
/*   Updated: 2017/03/04 14:42:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_function_rl(t_lsto **lsti, t_lsto *lst,
		t_lsto *(*f1)(char*), t_lsto *(*f2)(t_lsto*))
{
	char			*s1;
	t_lsto			*lstj;
	struct stat		sb;
	ssize_t			xattr;
	acl_t			acl;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,
			((t_rep*)((*lsti)->content))->name);
	xattr = listxattr(s1, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(s1, ACL_TYPE_EXTENDED);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0
			&& ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		if (stat(s1, &sb) == 0)
		{
			/*
			if ((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH)
					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR)))
				lst = f1(s1);
			if (lst && (sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH)
					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR)))
			{
				lstj = f2(lst);
				*lsti = lst_addo_between(*lsti, lstj);
			}
			*/
//			if (((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH)
//					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR))) || (xattr > 0) || (acl != NULL))
			if (sb.st_mode & S_IRWXU)
				lst = f1(s1);
			//if (lst && ((((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH))
//					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR))) || (xattr > 0) || (acl != NULL)))
			if (sb.st_mode & S_IRWXU)
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
	ssize_t			xattr;
	acl_t			acl;

	s1 = ft_makepath(((t_rep*)((*lsti)->content))->path,
			((t_rep*)((*lsti)->content))->name);
	xattr = listxattr(s1, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(s1, ACL_TYPE_EXTENDED);
	if (ft_strcmp((((t_rep*)(*lsti)->content)->name), ".") != 0
			&& ft_strcmp((((t_rep*)(*lsti)->content)->name), "..") != 0)
	{
		ft_function_r4_p1(s1);
		if (stat(s1, &sb) == 0)
		{
//			if (((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH)
//					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR))) || (xattr > 0) || (acl != NULL))
			if (sb.st_mode & S_IRWXU)
				lst = f1(s1);
//			if (lst && ((((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH))
//					&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR))) || (xattr > 0) || (acl != NULL)))
			if (sb.st_mode & S_IRWXU)
				lstj = f2(lst);
			/*
			else if (!((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IROTH)
						&& ((sb.st_mode & S_IWUSR) || (sb.st_mode & S_IXUSR))))
				ft_function_r4_p2(s1, lsti);
			*/
			else if (!(sb.st_mode & S_IRWXU))
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
