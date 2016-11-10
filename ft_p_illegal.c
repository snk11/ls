/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_illegal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:38:49 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 16:14:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_p_illegal(t_ind *ind)
{
	if (ind->indillegal != 0)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd("illegal option -- ", 2);
		ft_putchar_fd(ind->indillegal, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n",2);
		ind->ind1 = 1;
		ind->inderror = 1;
		return (0);
	}
	return (1);

}
