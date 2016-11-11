/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_art.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 12:07:14 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 17:36:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_art(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(s, lstcmd, ind);
	lst = ft_getreplist4(s);
	ft_printname(s, lstcmd, ind);
	lsti = ft_printlist10(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_r(&lsti, lst, ft_getreplist, ft_printlist11);
	lsti = lstibegi;
	while (lsti)
		ft_function_r2(&lsti, lst, ft_getreplist4, ft_printlist10);
}
