/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:18:14 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 13:43:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_n(t_lsto *lstcmd, t_ind *ind)
{
	if (ind->indregfile == 1)
		ft_putstr("\n");
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
