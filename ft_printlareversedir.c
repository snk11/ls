/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlareversedir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:13:24 by syusof            #+#    #+#             */
/*   Updated: 2017/02/01 01:59:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlareversedir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	ft_print_n(s, lstcmd, ind);
	if (!ft_islnk(s))
	{
		lst = ft_getreplist4(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist14(lst);
	}
	else
	{
		lst = ft_getreplist5(s);
		ft_printname(s, lstcmd, ind);
		ft_printlist44(lst);
	}
}
