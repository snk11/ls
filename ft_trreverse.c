/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trreverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:34:44 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 17:12:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_trreverse(char *s, t_ind *ind)
{

	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;

	//if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
	if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 1)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 0 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && ind->indregfile == 1 && ind->inderror == 0)
		ft_putstr("\n");
	else if (ind->indposition > 1 && (ind->indregfile == 0 || ind->inderror == 0))
	{
		ind->inderror = 0;
		ind->indregfile = 0;
	}
	lst = ft_getreplist(s);
	//if (ind.indav3 || (ind.indav2  && i > 1 && (ind.indfirst == 1 && i > 2))  || (ind.indav2 && ind.indfirst == 0))
	//	if (ind->indfirst > 1)
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
