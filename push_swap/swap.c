/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 13:08:21 by syusof            #+#    #+#             */
/*   Updated: 2016/02/19 10:19:43 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"



# include <stdio.h>
void	swap(t_lst **lsta)
{
	t_lst	*lstmp;

	lstmp = NULL;
	if (lsta && (*lsta)->next)
	{
		lstmp = create_lst((*lsta)->next->content);
		if ((*lsta)->next->next)
			(*lsta)->next = (*lsta)->next->next;
		else
			(*lsta)->next = NULL;
		lst_add_del(lsta, &lstmp);
//		ft_putstr("sw\n");
	}
}
