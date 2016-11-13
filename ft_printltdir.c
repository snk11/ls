/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printltdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:04:27 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 08:51:44 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printltdir(char *s, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;

	ft_print_n(s, lstcmd, ind);
	lst = ft_getreplist(s);
	ft_printname(s, lstcmd, ind);
	ft_printlist13(lst);
}
