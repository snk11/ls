/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 19:47:41 by syusof           ###   ########.fr       */
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
	lst1 = ft_getprimelist(av);
	lstmp = lst1;
	if (ind->indreverse == 1 && ind->indt == 1)
		lst1 = ft_lst_sort(lst1,croissant_time_char);
	if (ind->indreverse == 1)
		lst1 = ft_lst_sort(lst1,decreasing_char);
	if (ind->indt == 1)
		lst1 = ft_lst_sort(lst1,decreasing_time_char);
	lst1begi = lst1;
	if (!av[1])
	{
		lst = ft_getreplist(".");
		ft_printlist(lst);
	}
//	else if(av[2])
	else
	{
		ft_p0error(lst1,ind,lstcmd);
		ft_p0regfile(lst1,ind,lstcmd);
		ind->index1 = ft_getindex(lst1,lstcmd);
		if(ft_strcmp((char*)lst1->content,"--") == 0 && (ind->index1 > 2 && ind->indone == 0))
		{
			if(ind->index1 == 1 && av[2] && ft_strcmp(av[2],".") == 0)
			ft_p1(lst1,ind, lstcmd);

		}
		else
			ft_p1(lst1,ind, lstcmd);
		if (ind->indtotal == 0)
		{
			lstmp = ft_create_lsto_char(".");
			lsta = lst_addo_down_char(lsta, lstmp);
			ft_p0error(lsta,ind,lstcmd);
			ft_p0regfile(lsta,ind,lstcmd);
			if(ft_strcmp((char*)lst1->content,"--") == 0 && ft_getindex(lst1,lstcmd) <= 2)
			{
			}
			else
				ft_p1(lsta, ind,lstcmd);
		}
	}
//	else if(av[1])
//	{
//		lstmp = ft_create_lsto_char(".");
//		lsta = lst_addo_down_char(lsta, lstmp);
//		ft_p1(lsta,ind);
//	}
	return (0);
}
