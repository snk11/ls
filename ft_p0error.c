/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:31:27 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 16:53:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd)
{
	char	*s;

	ind->indexyet = 0;
	while (lst1 && ind->indfts == 0)
	{
		s = (char*)lst1->content;
		if (ft_strcmp(s, "") == 0)
		{
			ind->indfts = 1;
			opendir(s);
			ft_putstr_fd("ls: fts_open: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			ind->inderror = 1;
		}
		else
			ft_p0error_p1(s, ind, lstcmd);
		lst1 = lst1->next;
	}
}
