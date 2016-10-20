/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlreversedir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:21:56 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 03:57:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlreversedir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	t_lsto		*lst;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	ft_printlist14(lst);
}
