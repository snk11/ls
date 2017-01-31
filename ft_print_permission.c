/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_permission.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 07:25:15 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 16:28:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_permission(char *s, t_loption loption)
{
	struct stat		sb;
	ssize_t			xattr;
	acl_t			acl;

	acl = NULL;
	xattr = 0;
	xattr = listxattr(s, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(s, ACL_TYPE_EXTENDED);
	if (lstat(s, &sb) == 0)
	{
		ft_print_permission_p1(sb);
		ft_print_permission_p2(sb);
		ft_print_permission_p3(sb);
		ft_print_permission_p4(sb);
		if (sb.st_mode & S_IROTH)
			ft_putchar('r');
		else
			ft_putchar('-');
		if (sb.st_mode & S_IWOTH)
			ft_putchar('w');
		else
			ft_putchar('-');
		if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
			ft_putchar('t');
		else if (sb.st_mode & S_IXOTH)
			ft_putchar('x');
		else if (sb.st_mode & S_ISVTX)
			ft_putchar('T');
		else
			ft_putchar('-');
		if (xattr > 0)
		{
			ft_putchar('@');
			ft_putchar(' ');
		}
		else if (acl != NULL)
		{
			ft_putchar('+');
			ft_putchar(' ');
		}
		else
			ft_putstr("  ");
	}
	else
	{
		ft_print_permission_p1(sb);
		ft_print_permission_p2(sb);
		ft_print_permission_p3(sb);
		ft_print_permission_p4(sb);
		if (sb.st_mode & S_IROTH)
			ft_putchar('r');
		else
			ft_putchar('-');
		if (sb.st_mode & S_IWOTH)
			ft_putchar('w');
		else
			ft_putchar('-');
		if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
			ft_putchar('t');
		else if (sb.st_mode & S_IXOTH)
			ft_putchar('x');
		else if (sb.st_mode & S_ISVTX)
			ft_putchar('T');
		else
			ft_putchar('-');
		if (xattr > 0)
		{
			ft_putchar('@');
			ft_putchar(' ');
		}
		else if (acl != NULL)
		{
			ft_putchar('+');
			ft_putchar(' ');
		}
		else
			ft_putstr("  ");
	}
}

void	ft_print_permission_p1(struct stat sb)
{
	if (S_ISLNK(sb.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else if (S_ISSOCK(sb.st_mode))
		ft_putchar('s');
	else if (S_ISBLK(sb.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(sb.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(sb.st_mode))
		ft_putchar('p');
	else if (S_ISREG(sb.st_mode))
		ft_putchar('-');
}

void	ft_print_permission_p2(struct stat sb)
{
	if (sb.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
}

void	ft_print_permission_p3(struct stat sb)
{
	if ((sb.st_mode & S_ISUID) && (sb.st_mode & S_IXUSR))
		ft_putchar('s');
	else if (sb.st_mode & S_IXUSR)
		ft_putchar('x');
	else if (sb.st_mode & S_ISUID)
		ft_putchar('S');
	else
		ft_putchar('-');
}

void	ft_print_permission_p4(struct stat sb)
{
	if (sb.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
		ft_putchar('s');
	else if (sb.st_mode & S_IXGRP)
		ft_putchar('x');
	else if (sb.st_mode & S_ISGID)
		ft_putchar('S');
	else
		ft_putchar('-');
}
