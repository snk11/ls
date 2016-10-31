/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 23:31:06 by syusof            #+#    #+#             */
/*   Updated: 2016/10/25 09:09:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_scan_option(char **av,t_ind *ind)
{

	int i;
	int j;
	int hyphenillegal;;

	i = 1;
	hyphenillegal = 0;
//	while (av[i] && av[i][0] == '-' && ft_strcmp(av[i],"-") != 0)
	while(av[i] && ft_strcmp(av[i],"-") != 0 && av[i][0] == '-' && ind->indillegal == 0 && ind->indhyphen == 0)
	{
		ind->indoption++;
//		if (ft_strcmp(av[i], "--") == 0)
//		{
//			ind->indone = 1;
//		}
//		else
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
				else if (av[i][j] == '-' && j == 1)
				{
					if(av[i][2])
						ind->indillegal = '-';
					ind->indhyphen = 1;
				}
				else if (ind->indillegal == 0)
					ind->indillegal = av[i][j];
				j++;
			}
		}
		i++;
	}
}


int		ft_scan_option2(char *av)
{

	int j;
	int	m;
	char	l;

	m = 0;
	l = 0;
	if(av && av[0] == '-' && l == 0 && m == 0)
	{
//		if (ft_strcmp(av[i], "--") == 0)
//		{
//			ind->indone = 1;
//		}
//		else
		{
			j = 1;
			while (av[j])
			{
				if (av[j] == 'R')
				{
				}
				else if (av[j] == 'a')
				{
				}
				else if (av[j] == 'r')
				{
				}
				else if (av[j] == 't')
				{
				}
				else if (av[j] == 'l')
				{
				}
				else if (av[j] == '1')
				{
				}
				else if (av[j] == '-' && j == 1)
				{
					if(av[2])
						l = '-';
					m = 1;
				}
				else if (l == 0)
					l = av[j];
				j++;
			}
		}
	}
	else
		return (0);
	if(l != 0)
		return (0);
	return (1);
}
