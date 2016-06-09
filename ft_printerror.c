/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 02:37:03 by syusof            #+#    #+#             */
/*   Updated: 2016/06/09 03:25:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_printerror(char **av)
{
	int	i;
	int ind1;

	i = 1;
	ind1 = 0;
	while(av[i])
	{
		if (ft_strcmp(av[i], "-1") != 0 && ft_strcmp(av[i], "--") != 0 && ft_strcmp(av[i], "-1R") != 0 && ft_strcmp(av[i],"-1a") != 0 && ft_strcmp(av[i],"-1r") != 0 && ft_strcmp(av[i],"-1t") != 0)
		{
			if (!opendir(av[i]) && ft_isdir(av[i]))
			{
				ft_putstr_fd("ls: ", 2);
				perror(av[i]);
			}
			if (!ft_isdir(av[i]))
			{
				ft_putstr(av[i]);
				ft_putstr("\n");
				ind1 = 1;
			}
		}
		i++;
	}
	if (ind1 == 1)
		ft_putstr("\n");
}
