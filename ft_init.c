/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:00:49 by syusof            #+#    #+#             */
/*   Updated: 2017/01/21 04:19:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_ind *ind)
{
	ind->indhyphsolo = 0;
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
	loption->frdevmin = 0;
	loption->frdevmaj = 0;
	loption->fsize = 0;
	loption->day = 2;
	loption->hour = 2;
	loption->minute = 2;
	loption->year = 0;
}
