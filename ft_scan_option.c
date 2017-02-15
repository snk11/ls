/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 23:31:06 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 22:30:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_scan_option(char **av, t_ind *ind)
{
	int		i;
	int		j;
	int		k;
	int		hyphenillegal;

	i = 1;
	hyphenillegal = 0;
	while (ind->inderror2 == 0 && av[i] && ft_strcmp(av[i], "--") != 0)
	{
		j = 1;
		if (av[i][0] != '-' || ft_strcmp(av[i], "-") == 0)
			ind->inderror2 = 1;
		while (ind->inderror2 == 0 && av[i][j] && hyphenillegal == 0)
		{
			hyphenillegal = ft_scan_option_p0(av, ind, i, j);
			j++;
		}
		i++;
	}
	if (ind->inderror2 == 0 && av[i] && ft_strcmp(av[i], "--") == 0)
		ind->indoption++;
	k = (ind->inderror2) ? i - 1 : i;
	i = 1;
	while (k > 1 && hyphenillegal == 0)
		ft_scan_option_p1(av, ind, &i, &k);
}

int		ft_scan_option_p0(char **av, t_ind *ind, int i, int j)
{
	if (av[i][j] != 'R' && av[i][j] != 'a' && av[i][j] != 'r' && av[i][j] != 't'
			&& av[i][j] != 'l' && av[i][j] != '1')
	{
		ind->indillegal = av[i][j];
		return (1);
	}
	return (0);
}

void	ft_scan_option_p1(char **av, t_ind *ind, int *i, int *k)
{
	int		j;

	ind->indoption++;
	j = 1;
	while (av[*i][j])
	{
		ft_scan_option_p1_p1(av, ind, *i, j);
		j++;
	}
	(*i)++;
	(*k)--;
}

void	ft_scan_option_p1_p1(char **av, t_ind *ind, int i, int j)
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
}
