/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:06:32 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 13:30:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printname(char *s, t_lsto *lstcmd, t_ind *ind)
{
	int	cnt;

	cnt = ft_countelem(lstcmd);
	/*
	if (ft_checkhyphencase(lstcmd, ind) == 1 && ind->indhyphsolo == 0)
	{
		ft_printname_p1(s, lstcmd, ind, cnt);
	}
	else if (ft_checkhyphencase(lstcmd, ind) == 0 || ind->indhyphsolo == 1)
	*/
	{
		if (ft_printname_p2(s, lstcmd, ind, cnt))
			;
		else
			ft_printname_p3(s, lstcmd, ind);
	}
}

void		ft_printname_p1(char *s, t_lsto *lstcmd, t_ind *ind, int cnt)
{
	if (ft_checkhyphencase_print(lstcmd, ind) == 1)
	{
	}
	else if (ind->indposition == 1 && cnt < 4)
	{
	}
	else if (ind->indposition == 1 && cnt >= 4)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	else if (ind->indposition >= 2)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
}

int			ft_printname_p2(char *s, t_lsto *lstcmd, t_ind *ind, int cnt)
{
	if ((cnt - ind->indoption) >= 2)
	{
		ft_putstr(s);
		ft_putstr(":\n");
		return (1);
	}
	/*
	if (ind->indoption > 0 && (cnt - ind->indoption) >= 2)
	{
		ft_putstr(s);
		ft_putstr(":\n");
		return (1);
	}
	else if ((ind->index1 == 1 && ind->indoption == 0)
			|| (ind->index1 == 0 && ind->indhyphsolo == 1)
			|| ind->indexyet == 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
		ind->indexyet = 1;
		return (1);
	}
	else if (((ind->index1 == (2 + ind->indoption)
					&& ft_checkhyphencase(lstcmd, ind) == 0)
				|| ind->indexyet == 1) && ft_strcmp(s, "--") == 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
		ind->indexyet = 1;
		return (1);
	}
	*/
	return (0);
}

void		ft_printname_p3(char *s, t_lsto *lstcmd, t_ind *ind)
{
	/*
	if (((ind->index1 == (2 + ind->indoption)
					&& ft_checkhyphencase(lstcmd, ind) == 0)
				|| ind->indexyet4 == 1))
	{
		ft_putstr(s);
		ft_putstr(":\n");
		ind->indexyet4 = 1;
	}
	*/
	if (ind->index1 >= (2 + ind->indoption))
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
	else if (ind->inderror == 1)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
}
