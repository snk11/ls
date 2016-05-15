/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/05/15 12:47:06 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_printlist(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;

	lst1 = NULL;
	lst2 = NULL;
	while (lstmp)
	{
		if (ft_isdir(lstmp) == 0)
		{
			lst_addo(&lst1, lstmp);
			if ( (((t_rep*)(lstmp)->content)->name)[0] != '.')
			{
//				ft_putstr(((t_name*)((lstmp))->content)->name);
//				ft_putstr("\n");
			}
		}
		else
		{
			lst_addo(&lst2, lstmp);
		}
		lstmp = lstmp->nextl;
	}
	while (lst1)
	{
		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	while (lst2)
	{
		if ( (((t_rep*)(lst2)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst2))->content)->name);
			ft_putstr("\n");
		}
		lst2 = lst2->next;
	}
}
