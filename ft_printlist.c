/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/02/20 11:57:01 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_printlist(t_lst *lstmp)
{
	while (lstmp)
	{
		if ( (((t_name*)(lstmp)->content)->name)[0] != '.')
		{
			ft_putstr(((t_name*)((lstmp))->content)->name);
			ft_putstr("\n");
		}
		lstmp = lstmp->next;
	}
}
