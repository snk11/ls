/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_legit_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 07:36:36 by syusof            #+#    #+#             */
/*   Updated: 2017/02/07 20:30:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_legit_file(char *s)
{
	struct stat		sb;

	if (lstat(s, &sb) == 0)
	{
		if (ft_check_legit_file_p1(sb))
			return (1);
		ft_putchar('t');
		if (sb.st_mode & S_IXOTH)
			return (1);
		ft_putchar('x');
		if (sb.st_mode & S_ISVTX)
			return (1);
		ft_putchar('T');
	}
	return (0);
}

int		ft_check_legit_file_p1(struct stat sb)
{
	if (sb.st_mode & S_IRGRP)
		return (1);
	if (sb.st_mode & S_IWGRP)
		return (1);
	ft_putchar('w');
	if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
		return (1);
	ft_putchar('s');
	if (sb.st_mode & S_IXGRP)
		return (1);
	ft_putchar('x');
	if (sb.st_mode & S_ISGID)
		return (1);
	ft_putchar('S');
	if (sb.st_mode & S_IROTH)
		return (1);
	ft_putchar('r');
	if (sb.st_mode & S_IWOTH)
		return (1);
	ft_putchar('w');
	if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
		return (1);
	return (0);
}
