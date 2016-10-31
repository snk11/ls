/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:58:11 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 04:03:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_at(char *s,t_lsto *lstcmd ,t_ind *ind)
{
	t_lsto			*lst;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	ft_printlist6(lst);
}
