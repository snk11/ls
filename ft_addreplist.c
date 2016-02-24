/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addreplist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 07:49:51 by syusof            #+#    #+#             */
/*   Updated: 2016/02/24 08:01:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void ft_addreplist(t_lst **lst1,char *str)
{
	t_lst *lstmp;

	lstmp = NULL;
	lstmp = ft_getreplist(str);
	while (lstmp)
	{
		lst_add1(lst1,lstmp);
		ft_push1stback(lst1);
		lstmp = lstmp->next;
	}
}
