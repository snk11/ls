/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkhyphen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:34:14 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 13:26:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkhyphen(t_lsto *lst1,t_lsto *lstcmd,t_ind *ind)
{
//	if(ft_strcmp((char*)lst1->content,"--") == 0 && ft_getindex(lst1,lstcmd) == 2 && ind->indone == 1)
//		return (1);
	if(ft_strcmp((char*)lst1->content,"--") == 0 && ft_getindex(lst1,lstcmd) == 0)
		return (1);
	return (0);
}
