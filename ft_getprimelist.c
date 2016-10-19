/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprimelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:01:33 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 18:51:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*ft_getprimelist(char **av,t_ind *ind)
{
	int j;
	t_lsto		*lstmp;
	t_lsto		*lsta;
	lsta = NULL;
	lstmp = NULL;
	j = 1;
	if(ind->indoption == 1)
		j++;
	while (av[j])
	{
		lstmp = ft_create_lsto_char(av[j]);
		lsta = lst_addo_down_char(lsta, lstmp);
		j++;
	}
	if(lsta)
		lsta = ft_lst_sort(lsta, croissant_char);
	return (lsta);
}
