/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:46:48 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 18:51:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_run_p1_p5(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->inda == 1 && ind->indreverse == 1 && ind->indl == 1)
	{
		ft_printlareversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indreverse == 1)
	{
		ft_areverse((char*)(lst1->content), ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indt == 1)
	{
		ft_at((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indr == 1)
	{
		ft_ar((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}

int		ft_ls_run_p1_p6(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->inda == 1 && ind->indl == 1)
	{
		ft_printladir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indr == 1 && ind->indt == 1)
	{
		ft_rt((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indr == 1 && ind->indreverse == 1)
	{
		ft_rreverse((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indl == 1 && ind->indr == 1)
	{
		ft_printlrdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}

int		ft_ls_run_p1_p7(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indl == 1 && ind->indt == 1)
	{
		ft_printltdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indl == 1 && ind->indreverse == 1)
	{
		ft_printlreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indt == 1 && ind->indreverse == 1)
	{
		ft_treverse((char*)(lst1->content), ind);
		return (1);
	}
	else if (ind->indl == 1)
	{
		ft_printldir((char*)(lst1->content),lstcmd,ind);
		return (1);
	}
	return (0);
}

int		ft_ls_run_p1_p8(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indr == 1)
	{
		ft_r((char*)(lst1->content),lstcmd, ind);
		return (1);
	}
	else if (ind->inda == 1)
	{
		ft_a((char*)(lst1->content), ind);
		return (1);
	}
	else if (ind->indt == 1)
	{
		ft_t((char*)(lst1->content),lstcmd, ind);
		return (1);
	}
	else if (ind->indreverse == 1)
	{
		ft_reverse((char*)(lst1->content), ind);
		return (1);
	}
	return (0);
}
