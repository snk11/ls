/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlatdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:46:52 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 03:45:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlatdir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	t_lsto		*lst;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	ft_printlist13(lst);
}
