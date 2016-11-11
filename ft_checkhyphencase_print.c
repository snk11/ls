/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkhyphencase_print.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:22:31 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 17:47:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkhyphencase_print(t_lsto *lst1, t_ind *ind)
{
	int	cnt;
	int	cnt2;
	int	c1;

	c1 = 0;
	cnt = 0;
	cnt2 = 0;
	cnt2 = ft_countelem(lst1);
	if (cnt2 == 2)
	{
		while (lst1)
		{
			if (cnt == 1 && ind->indoption > 0 && ind->indillegal == 0
					&& ft_strcmp((char*)lst1->content, "--") == 0 && c1 == 0)
				return (1);
			if (ft_strcmp((char*)lst1->content, "--") == 0 && cnt == 0)
				c1 = 1;
			cnt++;
			lst1 = lst1->next;
		}
	}
	else if (cnt2 == 1)
		return (1);
	return (0);
}
