/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:07:37 by syusof            #+#    #+#             */
/*   Updated: 2017/02/13 15:52:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl_p2_p1(t_loption loption, struct stat sb)
{
	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		ft_putstr(" ");
		ft_putwidth(ft_itoa(major(sb.st_rdev)), loption.frdevmaj);
		ft_putstr(", ");
	}
	else if (loption.indrdev)
	{
		ft_putwidth("", loption.frdevmaj);
		ft_putstr("  ");
	}
}

void	ft_wl_p3(t_loption loption, struct stat sb)
{
	int i;

	if (loption.year > 5)
	{
		ft_putstr(ft_getyear_str(ctime(&(sb.st_mtime))));
	}
	else
	{
		i = 5 - loption.year;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
		ft_putstr(ft_getyear_str(ctime(&(sb.st_mtime))));
	}
	ft_putstr(" ");
}

void	ft_wl_p4(t_loption loption, struct stat sb)
{
	ft_putwidth(ft_getday_str(ctime(&(sb.st_mtime))), loption.day);
	ft_putstr(" ");
	ft_putstr(" ");
	ft_putstr(ft_getyear_str(ctime(&(sb.st_mtime))));
	ft_putstr(" ");
}

void	ft_wl_p5(t_loption loption, struct stat sb)
{
	int		i;

	if (loption.year > 5)
	{
		i = loption.year - 5;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
		ft_puttime(ctime(&(sb.st_mtime)));
	}
	else
		ft_puttime(ctime(&(sb.st_mtime)));
	ft_putstr(" ");
}
