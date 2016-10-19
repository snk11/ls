/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:43:47 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 13:30:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_treverse(char *s, t_ind *ind)
{
	t_lsto			*lst;

//	if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
	if (ind->indfirst > 1 && ind->indregfile == 1 && ind->inderror == 1)
		ft_putstr("\n");
	else if (ind->indfirst > 1 && ind->indregfile == 0 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indfirst > 1 && ind->indregfile == 1 && ind->inderror == 0)
					ft_putstr("\n");
	else if (ind->indfirst > 1 && (ind->indregfile == 0 || ind->inderror == 0))
	{
		ind->inderror = 0;
		ind->indregfile = 0;
	}
	lst = ft_getreplist(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	if (ind->index1 > 0)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	ft_printlist15(lst);
}
