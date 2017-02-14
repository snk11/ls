/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:25:58 by syusof            #+#    #+#             */
/*   Updated: 2017/02/14 12:48:35 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_p1(char **av, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst1;

	lst1 = NULL;
	lst1 = ft_getprimelist(av, ind);
	/*
	if (ind->indillegal == 0 && ft_checkhyphencase(lstcmd, ind)
			&& ft_checkhyphencase_print(lstcmd, ind))
		ft_ls_p1_p1(lstcmd, ind);
	else if (lst1)
	*/
	if (lst1)
		ft_ls_p1_p2(lst1, lstcmd, ind);
	else
		ft_ls_p1_p3(lstcmd, ind);
}
