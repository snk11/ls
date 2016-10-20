/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_permission.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 07:25:15 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 06:51:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_permission(char *s)
{
	struct stat		sb;

	lstat(s, &sb);
	if(S_ISLNK(sb.st_mode))
		ft_putchar('l');
	else if(S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else if(S_ISSOCK(sb.st_mode))
		ft_putchar('s');
	else if(S_ISBLK(sb.st_mode))
		ft_putchar('b');
	else if(S_ISCHR(sb.st_mode))
		ft_putchar('c');
	else if(S_ISFIFO(sb.st_mode))
		ft_putchar('p');
	else if(S_ISREG(sb.st_mode))
		ft_putchar('-');
	if(sb.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IXUSR)
		ft_putchar('x');
	else if(sb.st_mode & S_ISUID)
		ft_putchar('S');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
		ft_putchar('s');
	else if(sb.st_mode & S_IXGRP)
		ft_putchar('x');
	else if(sb.st_mode & S_ISGID)
		ft_putchar('S');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if(sb.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
		ft_putchar('t');
	else if(sb.st_mode & S_IXOTH)
		ft_putchar('x');
	else if(sb.st_mode & S_ISVTX)
		ft_putchar('T');
	else
		ft_putchar('-');
}
