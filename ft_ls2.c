/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:37:44 by syusof            #+#    #+#             */
/*   Updated: 2017/03/08 06:13:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void			ft_ls_p1_p1(t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lstmp = NULL;
	lsta = NULL;
	lstmp = ft_create_lsto_char2(".");
	lsta = lst_addo_down_char(lsta, lstmp);
	lsta = ft_lst_sort(lsta, croissant_char);
	ft_p0error(lsta, ind);
	if (ind->indfts == 0)
	{
		ft_p0regfile(lsta, ind, lstcmd);
		ft_ls_run(lsta, ind, lstcmd);
	}
}
*/
void			ft_ls_p1_p2(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lsta;

	lsta = NULL;
	lst1 = ft_lst_sort(lst1, croissant_char);
	ft_p0error(lst1, ind, &lsta);
	if (ind->indreverse == 1 && ind->indt == 1)
		lsta = ft_lst_sort(lsta, croissant_time_char);
	else if (ind->indreverse == 1)
		lsta = ft_lst_sort(lsta, decreasing_char);
	else if (ind->indt == 1)
		lsta = ft_lst_sort(lsta, decreasing_time_char);
	if (ind->indfts == 0)
	{
		ft_p0regfile(lsta, ind, lstcmd);
		ind->index1 = ft_getindex(lsta, lstcmd);
		ft_ls_run(lsta, ind, lstcmd);
	}
}

void			ft_ls_p1_p3(t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lstmp;
	t_lsto		*lsta;
	t_lsto		*lstb;

	lstmp = NULL;
	lsta = NULL;
	lstb = NULL;
	lstmp = ft_create_lsto_char2(".");
	lsta = lst_addo_down_char(lsta, lstmp);
	lsta = ft_lst_sort(lsta, croissant_char);
	ft_p0error(lsta, ind, &lstb);
	if (ind->indfts == 0)
	{
		ft_p0regfile(lsta, ind, lstcmd);
		ft_ls_run(lsta, ind, lstcmd);
	}
}
