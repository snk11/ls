/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:11:31 by syusof            #+#    #+#             */
/*   Updated: 2015/06/01 19:50:46 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_lst **lsta)
{
	t_lst	*lstmp;
	t_lst	*lstmp2;
	
	lstmp = (*lsta);
	lstmp2 = lstmp->next;
	while ((*lsta)->next != NULL)
		(*lsta) = (*lsta)->next;
	(*lsta)->next = lstmp;
	lstmp->next = NULL;
	(*lsta) = lstmp2;
}
