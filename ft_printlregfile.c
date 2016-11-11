/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlregfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:31:45 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 17:37:59 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlregfile(t_lsto *lst1)
{
	t_loption	loption;
	ssize_t		r;
	t_rep	*e;
	t_lsto	*lstmp;

	lstmp = NULL;
	ft_init2(&loption);
	(e = (t_rep*)malloc(sizeof(t_rep)));
	{
		lstmp = ft_create_lsto(e);
		((t_rep*)(lstmp->content))->name = (char*)lst1->content;
		((t_rep*)(lstmp->content))->path = ".";
	}
	ft_width2(lstmp,&loption);
	ft_wl2(lstmp,loption);
}
