/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printla.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 14:35:43 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 09:27:34 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printladir(char *s,t_lsto *lstcmd,t_ind *ind)
{
	t_lsto		*lst;


	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist4(s);
	ft_printname(s,lstcmd,ind);
	ft_printlist7(lst);
}
