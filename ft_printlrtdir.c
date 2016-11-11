/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlrtdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:28:02 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 16:01:53 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlrtdir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	lsti = ft_printlist17(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_r(&lsti, lst, ft_getreplist, ft_printlist11);
	lsti = lstibegi;
	while (lsti)
		ft_function_r2(&lsti, lst, ft_getreplist, ft_printlist17);
}
