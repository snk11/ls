/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printldir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:27:31 by syusof            #+#    #+#             */
/*   Updated: 2017/02/13 17:51:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printldir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	ft_print_n(lstcmd, ind);
	if (!ft_islnk(s))
	{
		lst = ft_getreplist(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist7(lst);
	}
	else if (ft_islnk(s))
		ft_printl_link(s);
	else
	{
		lst = ft_getreplist5(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist37(lst);
	}
}
