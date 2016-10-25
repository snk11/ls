/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:00:49 by syusof            #+#    #+#             */
/*   Updated: 2016/10/25 14:10:54 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_ind *ind)
{
	ind->indfts = 0;
	ind->indexyet = 0;
	ind->indexyet2 = 0;
	ind->indexyet3 = 0;
	ind->indexyet4 = 0;
	ind->indhyphen = 0;
	ind->inderror = 0;
	ind->indregfile = 0;
	ind->index1 = 0;
	ind->indposition = 0;
	ind->indtotal = 0;
	ind->indone = 0;
	ind->indr = 0;
	ind->indt = 0;
	ind->ind2 = 0;
	ind->indillegal = 0;
	ind->indl = 0;
	ind->indoption = 0;
	ind->ind1 = 0;
}

void	ft_init2(t_loption *loption)
{
	loption->link = 0;
	loption->uname = 0;
	loption->gname = 0;
	loption->fsize = 0;
	loption->month = 0;
	loption->day = 0;
	loption->hour = 0;
	loption->minute = 0;
	loption->year = 0;
}
