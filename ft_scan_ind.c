/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 05:53:39 by syusof            #+#    #+#             */
/*   Updated: 2016/06/12 23:39:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_scan_ind(char **av,t_ind *ind)
{
	int i;

	i = 1;
	while(av[i])
	{
		if (ft_strcmp(av[i], "-1") == 0 || ft_strcmp(av[i], "--") == 0)
		{
			ind->indone = 1;
		}
		else if (ft_strcmp(av[i],"-1t") == 0)
		{
			ind->indt = 1;
		}
		else if (ft_strcmp(av[i], "-1R")== 0)
		{
			ind->indr = 1;
		}
		i++;
	}
}
