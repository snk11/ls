/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 05:53:39 by syusof            #+#    #+#             */
/*   Updated: 2017/02/09 12:14:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_scan_ind(char **av, t_ind *ind)
{
	if (av[1])
	{
		if (ft_strcmp(av[1], "--") == 0)
			ind->indhyphen = 1;
		else if (ft_strcmp(av[1], "-1") == 0)
			ind->indone = 1;
		else if (ft_strcmp(av[1], "-1t") == 0)
			ind->indt = 1;
		else if (ft_strcmp(av[1], "-1R") == 0)
			ind->indr = 1;
	}
}
