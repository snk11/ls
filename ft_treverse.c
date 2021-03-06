/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:43:47 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 17:34:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_treverse(char *s, t_ind *ind)
{
	t_lsto			*lst;

	if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 1)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 0 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && (ind->indregfile == 0
				|| ind->inderror == 0))
	{
		ind->inderror = 0;
		ind->indregfile = 0;
	}
	lst = ft_getreplist(s);
	ft_printlist15(lst);
}
