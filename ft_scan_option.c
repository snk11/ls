/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 23:31:06 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 12:51:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_scan_option(char **av,t_ind *ind)
{

	int i;
	int j;

	i = 1;
	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i],"-") != 0)
	{
		ind->indoption = 1;
		if (ft_strcmp(av[i], "--") == 0)
		{
			ind->indone = 1;
		}
		else
		{
			j = 1;
			while (av[i][j])
			{
				if (av[i][j] == 'R')
					ind->indr = 1;
				else if (av[i][j] == 'a')
					ind->inda = 1;
				else if (av[i][j] == 'r')
					ind->indreverse = 1;
				else if (av[i][j] == 't')
					ind->indt = 1;
				else if (av[i][j] == 'l')
					ind->indl = 1;
				else if (av[i][j] == '1')
					ind->indone = 1;
				else if (ind->indillegal == 0)
					ind->indillegal = av[i][j];
				j++;
			}
		}
		i++;
	}
}
