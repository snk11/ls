/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printldir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:27:31 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 16:30:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printldir(char *s,t_ind *ind)
{
	t_lsto		*lst;

	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	ft_printlist7(lst);
}
