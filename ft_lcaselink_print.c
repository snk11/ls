/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcaselink_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:14:48 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 21:31:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lcaselink_print(char *s, t_lsto *lstcmd, t_ind *ind,t_lsto *(*f1)(char*))
{
	t_lsto *lst;

	lst = NULL;
	if (ft_islnk(ft_makepath(".", s)))
	{
		ft_print_n(s, lstcmd, ind);
		lst = f1(s);
		if (lst)
		{
			ft_printname(s, lstcmd, ind);
			ft_printlist7(lst);
		}
		return (1);
	}
	return (0);
}
