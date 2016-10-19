/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkhyphencase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:48:47 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 14:16:11 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkhyphencase(t_lsto *lst1,t_ind *ind)
{
	int	cnt;
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	cnt = 0;
	while(lst1)
	{
		if (cnt == 1 && ind->indillegal == 0 && ft_strcmp((char*)lst1->content,"--") == 0 && c1 == 0)
			return (1);
		if (ft_strcmp((char*)lst1->content,"--") == 0 && cnt == 0)
			c1 = 1;
		if (ft_strcmp((char*)lst1->content,"--") == 0 && cnt == 1)
			c2 = 1;
		cnt++;
		lst1 = lst1->next;
	}
	if (c1 == 1 && c2 == 0)
		return (1);
	return (0);
}
