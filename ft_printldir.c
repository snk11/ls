/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printldir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:27:31 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 20:27:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printldir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	printf("path = %s\n", ft_cutpath_lcaselink(s));
	printf("name = %s\n", ft_cutname_lcaselink(s));
	if (!ft_islnk(ft_makepath(".", s)))
	{
		ft_print_n(s, lstcmd, ind);
		lst = ft_getreplist(s);
		if (lst)
		{
			ft_printname(s, lstcmd, ind);
			ft_printlist7(lst);
		}
	}
	else
	{

	}
}
