/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printl_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:35:08 by syusof            #+#    #+#             */
/*   Updated: 2017/02/13 17:48:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printl_link(char *s)
{
	t_loption	loption;
	t_rep		*e;
	t_lsto		*lstmp;

	lstmp = NULL;
	ft_init2(&loption);
	e = (t_rep*)malloc(sizeof(t_rep));
	{
		e->name = ft_memmove2(s);
		if (s[0] == '/')
			e->path = ft_memmove2("");
		else
			e->path = ft_memmove2(".");
		lstmp = ft_create_lsto2(e);
	}
	ft_width2(lstmp, &loption);
	ft_wl2(lstmp, loption);
}
