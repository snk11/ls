/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlrreversedir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:03:45 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 08:50:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlrreversedir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(s, lstcmd, ind);
	lst = ft_getreplist(s);
	ft_printname(s, lstcmd, ind);
	lsti = ft_printlist18(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist19);
	lsti = lstibegi;
	while (lsti)
		ft_function_r4(&lsti, lst, ft_getreplist4, ft_printlist18);
}
