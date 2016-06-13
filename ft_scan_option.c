/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 23:31:06 by syusof            #+#    #+#             */
/*   Updated: 2016/06/13 03:11:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_scan_option(char *s,t_ind *ind)
{

	int i;

	i = 1;
	if (s)
	{
		if (ft_strcmp(s, "-1") == 0 || ft_strcmp(s, "--") == 0)
		{
			ind->indone = 1;
		}
		else
		{
			while (*s)
			{
				if (*s == 'R')
					ind->indr = 1;
				else if (*s == 'a')
					ind->inda = 1;
				else if (*s == 'r')
					ind->indreverse = 1;
				else if (*s == 't')
					ind->indt = 1;
				else if (*s == 'l')
					ind->indl = 1;
				else
					ind->indillegal = *s;
				s++;
			}
		}
//		else if (ft_strcmp(s,"-1t") == 0)
//		{
//			ind->indt = 1;
//		}
//		else if (ft_strcmp(s, "-1R")== 0)
//		{
//			ind->indr = 1;
//		}
//		i++;
	}
}
