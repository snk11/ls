/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprimelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 20:01:33 by syusof            #+#    #+#             */
/*   Updated: 2017/03/04 12:51:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*ft_getprimelist(char **av, t_ind *ind)
{
	int			j;
	int			k;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lsta = NULL;
	lstmp = NULL;
	k = 0;
	j = 1;
	k = ind->indoption;
	while (k > 0)
	{
		k--;
		j++;
	}
	while (av[j])
	{
		lstmp = ft_create_lsto_char2(av[j]);
		lsta = lst_addo_down_char(lsta, lstmp);
		j++;
	}
	if (lsta)
		lsta = ft_lst_sort(lsta, croissant_char);
	return (lsta);
}

t_lsto		*ft_getprimelist2(char **av)
{
	int			j;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lsta = NULL;
	lstmp = NULL;
	j = 3;
	while (av[j])
	{
		lstmp = ft_create_lsto_char2(av[j]);
		lsta = lst_addo_down_char(lsta, lstmp);
		j++;
	}
	if (lsta)
		lsta = ft_lst_sort(lsta, croissant_char);
	return (lsta);
}
