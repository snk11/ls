/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:52:00 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 16:52:37 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_puttime(char *s)
{
	int		cnt;
	int		cnt2;

	cnt = 0;
	while (*s && cnt < 3)
	{
		while (*s && *s != ' ')
			s++;
		while (*s && *s == ' ')
			s++;
		cnt++;
	}
	cnt2 = 0;
	while (*s && *s != ' ' && cnt2 < 2)
	{
		if (*s == ':')
			cnt2++;
		if(cnt2 < 2)
			write(1, s, 1);
		s++;
	}
}
