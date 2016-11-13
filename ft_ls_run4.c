/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_run4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:55:02 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 07:13:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_run_p2(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind)
{
	t_lsto		*lst;
	t_lsto		*lstj;

	lst = NULL;
	lstj = NULL;
	ft_print_n((char*)lst1->content, lstcmd, ind);
	lst = ft_getreplist((char*)(lst1->content));
	ft_printname((char*)lst1->content, lstcmd, ind);
	lstj = ft_printlist2(lst);
}
