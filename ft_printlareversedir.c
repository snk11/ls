/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlareversedir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:13:24 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 16:15:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlareversedir(char *s,t_ind *ind)
{
	t_lsto		*lst;

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
	lst = ft_getreplist4(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	ft_printlist14(lst);
}
