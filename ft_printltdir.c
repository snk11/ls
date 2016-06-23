/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printltdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:04:27 by syusof            #+#    #+#             */
/*   Updated: 2016/06/23 11:16:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printltdir(char *s,t_ind *ind)
{
	t_lst		*lst;

	if (ind->indfirst > 1 && ind->inder1 == 0)
		ft_putstr("\n");
	ind->inder1 = 0;
	lst = ft_getreplist(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	ft_printlist13(lst);
}
