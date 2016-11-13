/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_fullfield.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:41:32 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 11:45:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lst_fullfield(t_lsto *lst1, t_lsto **lstmp)
{
	((t_rep*)((*lstmp)->content))->name =
		ft_memmove2(((t_rep*)((lst1)->content))->name);
	((t_rep*)((*lstmp)->content))->path =
		ft_memmove2(((t_rep*)((lst1)->content))->path);
}
