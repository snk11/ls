/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 19:26:19 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
//# include "push_swap/push_swap.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_lsto			*lstcmd;
	t_lsto			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;
	t_lsto			*lst1;
	t_lsto			*lst1begi;
	int				i;
	int				inderror;
	t_ind			*ind;
	int j;
	char 			*s1;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lstcmd = NULL;
	lsta = NULL;
	lstmp = NULL;
	ind = NULL;
	ind = (t_ind*)malloc(sizeof(t_ind));
	lst = NULL;
	lstj = NULL;
	lst1 = NULL;
	lstibegi = NULL;
	lst1begi = NULL;
	i = 1;
	inderror = 0;
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
	if (ft_p_illegal(ind))
	{

		lst1 = ft_getprimelist(av,ind);
//		if(lst1)
//			ft_printlst(lst1);
		if(lst1)
		{
			if (ind->indreverse == 1 && ind->indt == 1)
				lst1 = ft_lst_sort(lst1,croissant_time_char);
			else if (ind->indreverse == 1)
				lst1 = ft_lst_sort(lst1,decreasing_char);
			else if (ind->indt == 1)
				lst1 = ft_lst_sort(lst1,decreasing_time_char);
		}
		if (!av[1])
		{
			lst = ft_getreplist(".");
			ft_printlist(lst);
		}
		//	else if(av[2])
		else
		{
			if(lst1)
			{
				ft_p0error(lst1,ind,lstcmd);
				ft_p0regfile(lst1,ind,lstcmd);
				ind->index1 = ft_getindex(lst1,lstcmd);
				ft_p1(lst1,ind, lstcmd);
			}
		if (((ind->indtotal == 0 && ind->indillegal == 0 && ft_checkhyphencase(lstcmd,ind) == 1) && ft_checkhyphencase_print(lstcmd,ind)) || (lst1 == NULL && lstcmd && ft_strcmp((char*)lstcmd->content,"--") == 0))
		{
			lstmp = ft_create_lsto_char(".");
			lsta = lst_addo_down_char(lsta, lstmp);
			ft_p0error(lsta,ind,lstcmd);
			ft_p0regfile(lsta,ind,lstcmd);
			ft_p1(lsta, ind,lstcmd);
		}
	}
		//	else if(av[1])
		//	{
		//		lstmp = ft_create_lsto_char(".");
		//		lsta = lst_addo_down_char(lsta, lstmp);
		//		ft_p1(lsta,ind);
		//	}
	}
	return (0);
}
