/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlregfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:31:45 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 18:23:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlregfile(char *s)
{
	struct stat		sb;

	if ( s[0] != '.')
	{
		stat(s,&sb);
		ft_print_permission(s);
		ft_putstr("  ");
		ft_putstr(ft_ustoa(sb.st_nlink));
		ft_putstr(" ");
		ft_putstr(getpwuid(sb.st_uid)->pw_name);
		ft_putstr("  ");
		ft_putstr(getgrgid(sb.st_gid)->gr_name);
		ft_putstr("  ");
		ft_putstr(ft_lldtoa(sb.st_size));
		ft_putstr(" ");
		ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
		ft_putstr(" ");
		ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
		ft_putstr(" ");
		ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
		ft_putstr(" ");
		ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
		ft_putstr(" ");
		ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
		ft_putstr(" ");
		ft_putstr(s);
		ft_putstr("\n");
	}
}
