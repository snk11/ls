/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:00:53 by syusof            #+#    #+#             */
/*   Updated: 2015/06/01 16:03:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **lsta)
{
	t_lst	*lstmp;
	t_lst	*lstmp2;
	
	lstmp = (*lsta);
	lstmp2 = (*lsta)->next;
	while ((*lsta)->next != NULL)
		(*lsta) = (*lsta)->next;

	(*lsta)->next = lstmp;
	lstmp->next = NULL;
	(*lsta) = lstmp2;
	}
