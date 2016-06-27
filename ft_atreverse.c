/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atreverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 17:25:17 by syusof            #+#    #+#             */
/*   Updated: 2016/06/27 15:35:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_atreverse(char *s, t_ind *ind)
{
	t_lst			*lst;

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
	ft_printlist9(lst);
}