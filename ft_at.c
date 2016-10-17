/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:58:11 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 16:34:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_at(char *s, t_ind *ind)
{
	t_lsto			*lst;

//	if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist4(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	if (ind->indfirst > 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	ft_printlist6(lst);
}
