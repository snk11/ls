/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:25:58 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 19:35:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_p1(char **av,t_lsto *lstcmd, t_ind *ind)
{
	t_lsto			*lst1;
	int				i;
	int j;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lst1 = NULL;
	lstmp = NULL;
	lsta = NULL;
	lst1 = ft_getprimelist(av,ind);
	if(ind->indillegal == 0 && ft_checkhyphencase(lstcmd,ind) && ft_checkhyphencase_print(lstcmd,ind) )
	{
		lstmp = ft_create_lsto_char(".");
		lsta = ft_lst_sort(lsta,croissant_char);
		lsta = lst_addo_down_char(lsta, lstmp);
		ft_p0error(lsta,ind,lstcmd);
		if(ind->indfts == 0)
		{
			ft_p0regfile(lsta,ind,lstcmd);
			ft_ls_run(lsta, ind,lstcmd);
		}
	}
	else if(lst1)
	{
		lst1 = ft_lst_sort(lst1,croissant_char);
		ft_p0error(lst1,ind,lstcmd);
		if (ind->indreverse == 1 && ind->indt == 1)
			lst1 = ft_lst_sort(lst1,croissant_time_char);
		else if (ind->indreverse == 1)
			lst1 = ft_lst_sort(lst1,decreasing_char);
		else if (ind->indt == 1)
			lst1 = ft_lst_sort(lst1,decreasing_time_char);
		if(ind->indfts == 0)
		{
			ft_p0regfile(lst1,ind,lstcmd);
			ind->index1 = ft_getindex(lst1,lstcmd);
			ft_ls_run(lst1,ind, lstcmd);
		}
	}
	else
	{
		lstmp = ft_create_lsto_char(".");
		lsta = lst_addo_down_char(lsta, lstmp);
		lsta = ft_lst_sort(lsta,croissant_char);
		ft_p0error(lsta,ind,lstcmd);
		if(ind->indfts == 0)
		{
			ft_p0regfile(lsta,ind,lstcmd);
			ft_ls_run(lsta, ind,lstcmd);
		}
	}
}
