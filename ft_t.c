/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 07:00:10 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 03:00:00 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_t(char *s, t_lsto *lstcmd,t_ind *ind)
{
	t_lsto			*lst;

//				printf("char = %s,indfirst = %d,indregfile = %d,inderror = %d\n",s,ind->indfirst,ind->indregfile,ind->inderror);

	ft_print_n(s,lstcmd,ind);
	lst = ft_getreplist(s);
	ft_printname(s,lstcmd,ind);
	ft_printlist6(lst);
}
