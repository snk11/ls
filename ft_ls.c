/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 07:02:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_lsto			*lstcmd;
	t_lsto			*lst;
	t_ind			*ind;
	int				j;

	lstcmd = NULL;
	ind = NULL;
	ind = (t_ind*)malloc(sizeof(t_ind));
	lst = NULL;
	ft_ls_p2(av, &lstcmd);
	ft_init(ind);
	ft_scan_option(av, ind);
	if (!av[1] || (ac == 2 && ft_strcmp(av[1], "--") == 0))
	{
		lst = ft_getreplist(".");
		ft_printlist(lst);
	}
	else if (ft_p_illegal(ind))
		ft_ls_p1(av, lstcmd, ind);
	return (0);
}
