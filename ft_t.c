/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 07:00:10 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 13:30:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_t(char *s, t_ind *ind)
{
	t_lsto			*lst;

//				printf("char = %s,indfirst = %d,indregfile = %d,inderror = %d\n",s,ind->indfirst,ind->indregfile,ind->inderror);
	if (ind->indregfile == 1 && ind->inderror == 1)
		ft_putstr("\n");
	else if (ind->indfirst > 1 && ind->indregfile == 0 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indregfile == 1 && ind->inderror == 0)
					ft_putstr("\n");
	if (ind->indfirst > 1 && (ind->indregfile == 0 || ind->inderror == 0))
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
	ft_printlist6(lst);
}
