/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlatrreversedir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:50:57 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 15:52:32 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void ft_printlatrreversedir(char *s, t_lsto *lstcmd,t_ind *ind)
{
	struct stat		sb;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	if (ind->indtotal != 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	lsti = ft_printlist31(lst);
	lstibegi = lsti;
	while (lsti)
		ft_function_r(&lsti, lst, ft_getreplist, ft_printlist30);
	lsti = lstibegi;
	while (lsti)
		ft_function_r2(&lsti, lst, ft_getreplist4, ft_printlist31);
}

