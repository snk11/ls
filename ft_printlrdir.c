/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlrdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:13:22 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 22:40:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlrdir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(lstcmd, ind);
	if (!ft_islnk(s))
	{
		lst = ft_getreplist(s);
		ft_printname(s, lstcmd, ind);
		lsti = ft_printlist8(lst);
		lstibegi = lsti;
		while (lsti)
			ft_function_rl(&lsti, lst, ft_getreplist, ft_printlist3);
		lstibegi = ft_lst_sort(lstibegi, croissant_pathname);
		lsti = lstibegi;
		while (lsti)
			ft_function_r4(&lsti, lst, ft_getreplist, ft_printlist8);
	}
	else if (ft_islnk(s))
		ft_printl_link(s);
	else
		ft_printlrdir_p1(s, lstcmd, ind);
}

void	ft_printlrdir_p1(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	lst = ft_getreplist5(s);
	ft_printname(s, lstcmd, ind);
	ft_printlist37(lst);
}
