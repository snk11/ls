/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 19:04:50 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 19:54:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getindex(t_lsto *lst1,t_lsto *lstcmd)
{
	int	cnt1;
	t_lsto	*lstmp;

	lstmp = lstcmd;
	cnt1 = 0;
	while (lstmp && lstmp != lst1)
	{
		lstmp = lstmp->next;
		if(cnt1 == -1)
			cnt1 = 1;
		else
			cnt1++;
	}
	return (cnt1);
}
