/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:09:48 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 18:53:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_run_p1(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{

	if(ft_ls_run_p1_p1(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p2(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p3(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p4(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p5(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p6(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p7(lst1, lstcmd, ind))
		return (1);
	else if(ft_ls_run_p1_p8(lst1, lstcmd, ind))
		return (1);
	return (0);
}

int		ft_ls_run_p1_p1(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indillegal != 0)
		return (1);
	else if (ind->indl == 1 && ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
	{
		ft_printlatrreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}

	else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
	{
		ft_atrreverse((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indl == 1)
	{
		ft_printlarreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}


int		ft_ls_run_p1_p2(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indreverse == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
	{
		ft_printltrreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
	{
		ft_printlartdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indreverse == 1 && ind->indt == 1 && ind->indl == 1)
	{
		ft_printlatreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indreverse == 1 && ind->indt == 1)
	{
		ft_atreverse((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}


int		ft_ls_run_p1_p3(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->inda == 1 && ind->indr == 1 && ind->indreverse == 1)
	{
		ft_arreverse((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indr == 1 && ind->indt == 1)
	{
		ft_art((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indreverse == 1 && ind->indr == 1 && ind->indt == 1)
	{
		ft_trreverse((char*)(lst1->content), ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indr == 1 && ind->indl == 1)
	{
		ft_printlardir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}

int		ft_ls_run_p1_p4(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indt == 1 && ind->indr == 1 && ind->indl == 1)
	{
		ft_printlrtdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indreverse == 1 && ind->indr == 1 && ind->indl == 1)
	{
		ft_printlrreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indt == 1 && ind->inda == 1 && ind->indl == 1)
	{
		ft_printlatdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indt == 1 && ind->indreverse == 1 && ind->indl == 1)
	{
		ft_printltreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}
