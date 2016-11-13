/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trreverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:34:44 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 10:30:27 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_trreverse(char *s, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_trreverse_p1(ind);
	lst = ft_getreplist(s);
	if (ind->indtotal != 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	lsti = ft_printlist22(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist23);
	lsti = lstibegi;
	while (lsti)
		ft_function_r4(&lsti, lst, ft_getreplist, ft_printlist22);
}

void		ft_trreverse_p1(t_ind *ind)
{
	if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 1)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 0 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && (ind->indregfile == 0
				|| ind->inderror == 0))
	{
		ind->inderror = 0;
		ind->indregfile = 0;
	}
}
