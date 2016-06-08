/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 07:00:10 by syusof            #+#    #+#             */
/*   Updated: 2016/06/09 00:47:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_t(char *s, t_ind ind, int i)
{
	t_lst			*lst;

	if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
		ft_putstr("\n");
	lst = ft_getreplist(s);
	if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	ft_printlist6(lst);
}