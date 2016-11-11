/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:45:07 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 15:11:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ar(char *s, t_lsto *lstcmd,t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist2(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_r(&lsti, lst, ft_getreplist4, ft_printlist3);
	lstibegi = ft_lst_sort(lstibegi, croissant_pathname);
	lsti = lstibegi;
	while (lsti)
		ft_function_r2(&lsti, lst, ft_getreplist4, ft_printlist2);
}
