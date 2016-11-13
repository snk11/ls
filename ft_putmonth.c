/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmonth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:42:33 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 16:38:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putmonth(int d)
{
	if (d == 0)
		ft_putstr("Jan");
	else if (d == 1)
		ft_putstr("Feb");
	else if (d == 2)
		ft_putstr("Mar");
	else if (d == 3)
		ft_putstr("Apr");
	else if (d == 4)
		ft_putstr("May");
	else if (d == 5)
		ft_putstr("Jun");
	else if (d == 6)
		ft_putstr("Jul");
	else if (d == 7)
		ft_putstr("Aug");
	else if (d == 8)
		ft_putstr("Sep");
	else if (d == 9)
		ft_putstr("Oct");
	else if (d == 10)
		ft_putstr("Nov");
	else if (d == 11)
		ft_putstr("Dec");
}


void		ft_putmonth1(char *s)
{
	while (*s && *s != ' ')
		s++;
	while (*s && *s == ' ')
		s++;
	while (*s && ft_isalpha(*s))
	{
		write(1, s, 1);
		s++;
	}
}
