/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:07:37 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 16:04:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl_p3(t_loption loption, struct stat sb, time_t curtime)
{
	int i;

	if (loption.year > 5)
	{
		ft_putyear(ctime(&(sb.st_mtime)));
	}
	else
	{
		i = 5 - loption.year;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
		ft_puttime(ctime(&(sb.st_mtime)));
	}
	ft_putstr(" ");
}

void	ft_wl_p4(t_loption loption, struct stat sb, time_t curtime)
{
	ft_putday(ctime(&(sb.st_mtime)));
	ft_putstr(" ");
	ft_putstr(" ");
//	ft_putstr(ctime(&(sb.st_mtime)));
//	ft_putstr("\n");
	ft_putstr(ft_getyear(ctime(&(sb.st_mtime))));
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
		ft_puttime(ctime(&(sb.st_mtime)));
	}
	else
		ft_puttime(ctime(&(sb.st_mtime)));
	ft_putstr(" ");
}
