/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_p11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:09:48 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 18:19:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_p1_p1(t_lsto *lst1, t_lsto *lstcmd,t_ind *ind)
{
	if (ind->indillegal != 0)
	{
		return (1);
	}
	else if (ind->indl == 1 && ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
	{
		ft_printlatrreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}

	else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
	{
		ft_atrreverse((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indl == 1)
	{
		ft_printlarreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->indreverse == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
	{
		ft_printltrreversedir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	else if (ind->inda == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
	{
		ft_printlartdir((char*)(lst1->content), lstcmd,ind);
		return (1);
	}
	return (0);
}
