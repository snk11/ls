/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlatreversedir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:10:35 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 16:30:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlatreversedir(char *s,t_ind *ind)
{
	t_lsto		*lst;

	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist4(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	ft_printlist24(lst);
}
