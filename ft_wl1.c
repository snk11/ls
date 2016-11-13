/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:07:37 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 11:10:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl_p3(t_loption loption, struct stat sb, time_t curtime)
{
	int i;

	if (loption.year > 5)
		ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
	else
	{
		i = 5 - loption.year;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
		ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
	}
	ft_putstr(" ");
}

void	ft_wl_p4(t_loption loption, struct stat sb, time_t curtime)
{
	ft_putwidth(ft_itoa((localtime(&(sb.st_mtime)))->tm_mday), loption.day);
	ft_putstr(" ");
	ft_putstr(" ");
	ft_putstr(ft_itoa((localtime(&(sb.st_mtime)))->tm_year + 1900));
	ft_putstr(" ");
}

void	ft_wl_p5(t_loption loption, struct stat sb, time_t curtime)
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
		ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour),
				loption.hour);
		ft_putstr(":");
		ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_min),
				loption.minute);
	}
	else
	{
		ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_hour),
				loption.hour);
		ft_putstr(":");
		ft_putwidth2(ft_itoa((localtime(&(sb.st_mtime)))->tm_min),
				loption.minute);
	}
	ft_putstr(" ");
}
