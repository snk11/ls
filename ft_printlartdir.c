/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlartdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:25:08 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 17:09:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlartdir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(lstcmd, ind);
	if (!ft_islnk(s))
	{
		lst = ft_getreplist4(s);
		ft_printname(s, lstcmd, ind);
		lsti = ft_printlist25(lst);
		lstibegi = lsti;
		while (lsti)
			ft_function_rl(&lsti, lst, ft_getreplist4, ft_printlist11);
		lsti = lstibegi;
		while (lsti)
			ft_function_r4(&lsti, lst, ft_getreplist4, ft_printlist25);
	}
	else if (ft_islnk(s))
		ft_printl_link(s);
	else
	{
		lst = ft_getreplist5(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist43(lst);
	}
}
