/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rreverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:33:51 by syusof            #+#    #+#             */
/*   Updated: 2017/02/09 12:13:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rreverse(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(lstcmd, ind);
	lst = ft_getreplist(s);
	ft_printname(s, lstcmd, ind);
	lsti = ft_printlist12(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist20);
	lsti = lstibegi;
	while (lsti)
		ft_function_r4(&lsti, lst, ft_getreplist, ft_printlist12);
}
