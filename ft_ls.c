/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 19:23:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
//# include "push_swap/push_swap.h"


int main(int ac,char **av)
{
	t_lsto			*lstcmd;
	t_lsto			*lst;
	t_lsto			*lst1;
	int				i;
	t_ind			*ind;
	int j;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lstcmd = NULL;
	lsta = NULL;
	lstmp = NULL;
	ind = NULL;
	ind = (t_ind*)malloc(sizeof(t_ind));
	lst = NULL;
	lst1 = NULL;
	i = 1;
	while(av[i])
	{
		lstmp = ft_create_lsto_char(av[i]);
		lstcmd = lst_addo_down_char(lstcmd,lstmp);
		i++;
	}
	lstmp = NULL;
	i = 1;
	ft_init(ind);
	ft_scan_option(av,ind);
	if (!av[1] || (ac == 2 && ft_strcmp(av[1],"--") == 0))
	{
		lst = ft_getreplist(".");
		ft_printlist(lst);
	}
	else if (ft_p_illegal(ind))
	{
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
	return (0);
}
