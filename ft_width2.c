/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:37:44 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 10:49:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_width2(t_lsto *lst1,t_loption *loption)
{
	struct stat		sb;

	while (lst1)
	{
		if(lstat(((t_rep*)(lst1->content))->name, &sb) == 0)
		{
			if(ft_strlen(ft_ustoa(sb.st_nlink)) > loption->link)
				loption->link = ft_strlen(ft_ustoa(sb.st_nlink));
			ft_width_p1(loption, sb);
			ft_width_p2(loption, sb);
		}
		lst1 = lst1->next;
	}
}
