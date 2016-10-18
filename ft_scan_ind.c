/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 05:53:39 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 19:47:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_scan_ind(char **av,t_ind *ind)
{
	int i;
	
	if (ft_strcmp(av[i], "--") == 0)

	if(av[1])
	{
		if (ft_strcmp(av[1], "--") == 0)
			ind->indhyphen = 1;
		else if (ft_strcmp(av[1], "-1") == 0)
			ind->indone = 1;
		else if (ft_strcmp(av[1],"-1t") == 0)
			ind->indt = 1;
		else if (ft_strcmp(av[1], "-1R")== 0)
			ind->indr = 1;
	}
}
