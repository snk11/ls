/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlareversedir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:13:24 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 07:54:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlareversedir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	ft_print_n(s, lstcmd, ind);
	lst = ft_getreplist4(s);
	ft_printname(s, lstcmd, ind);
	ft_printlist14(lst);
}
