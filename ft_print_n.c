/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:18:14 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 14:09:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_n(t_lsto *lstcmd, t_ind *ind)
{
	int	cnt;

	cnt = ft_countelem(lstcmd);
	if (ind->indregfile == 1)
		ft_putstr("\n");
	else if (ind->indexyet4 != 0)
		ft_putstr("\n");
	else if (ind->indregfile == 0 && ind->indexyet4 == 0)
		ind->indexyet4 = 1;
	/*
	if (ft_checkhyphencase(lstcmd, ind) == 1)
	{
		if (ind->indregfile == 1 || ind->inderror == 1)
			ft_putstr("\n");
		else if (ind->indposition > 1 && ind->indregfile == 0
				&& ind->inderror == 0)
			ft_putstr("\n");
	}
	else if (ft_checkhyphencase(lstcmd, ind) == 0)
	{
		if (ind->indregfile == 1 && ind->inderror == 0)
			ft_putstr("\n");
		else if (ind->indregfile == 1 && ind->inderror == 1)
			ft_putstr("\n");
		else if (ind->indposition > 1 && ind->indregfile == 0
				&& ind->inderror == 0)
			ft_putstr("\n");
	}
	*/
}
