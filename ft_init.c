/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:00:49 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 19:30:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_ind *ind)
{
	ind->indhyphen = 0;
	ind->inderror = 0;
	ind->indregfile = 0;
	ind->index1 = 0;
	ind->indfirst = 0;
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
