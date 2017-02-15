/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:06:32 by syusof            #+#    #+#             */
/*   Updated: 2017/02/15 22:32:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printname(char *s, t_lsto *lstcmd, t_ind *ind)
{
	int	cnt;

	cnt = ft_countelem(lstcmd);
	if ((cnt - ind->indoption) >= 2)
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
}
