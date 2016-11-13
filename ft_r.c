/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:45:09 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 06:41:32 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_r(char *s, t_lsto *lstcmd,t_ind *ind)
{

	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;

	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist2(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist3);
	lstibegi = ft_lst_sort(lstibegi,croissant_pathname);
	lsti = lstibegi;
	while (lsti)
		ft_function_r4(&lsti, lst, ft_getreplist, ft_printlist2);
}
