/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printla.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:35:43 by syusof            #+#    #+#             */
/*   Updated: 2016/06/27 15:28:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printladir(char *s,t_ind *ind)
{
	t_lst		*lst;

	if (ind->indfirst > 1)
		ft_putstr("\n");
	lst = ft_getreplist4(s);
	ft_printlist7(lst);
}
