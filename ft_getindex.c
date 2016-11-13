/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 19:04:50 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 06:54:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getindex(t_lsto *lst1, t_lsto *lstcmd)
{
	int		cnt1;
	t_lsto	*lstmp;

	lstmp = lstcmd;
	cnt1 = 0;
	while (lstmp && ft_strcmp((char*)lst1->content, (char*)lstmp->content) != 0)
	{
		lstmp = lstmp->next;
		cnt1++;
	}
	return (cnt1);
}
