/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlarreversedir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:24:45 by syusof            #+#    #+#             */
/*   Updated: 2017/03/15 17:09:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlarreversedir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;

	ft_print_n(lstcmd, ind);
	if (!ft_islnk(s))
	{
		lst = ft_getreplist4(s);
		ft_printname(s, lstcmd, ind);
		lsti = ft_printlist28(lst);
		lstibegi = lsti;
		while (lsti)
			ft_function_rl(&lsti, lst, ft_getreplist4, ft_printlist19);
		lsti = lstibegi;
		while (lsti)
			ft_function_r4(&lsti, lst, ft_getreplist4, ft_printlist28);
	}
	else if (ft_islnk(s))
		ft_printl_link(s);
	else
	{
		lst = ft_getreplist5(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist44(lst);
	}
}
