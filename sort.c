/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 16:06:31 by syusof            #+#    #+#             */
/*   Updated: 2015/11/04 17:42:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	swap(t_lst **lsta)
{
	t_lst	*lstmp;

	lstmp = NULL;
	if (lsta)
	{
		lstmp = (*lsta)->next;
		(*lsta)->next = (*lsta)->next->next;
		lst_add(lsta, &lstmp);
		lstmp = NULL;
		ft_putstr("sw\n");
	}
}

void		ft_sort(t_lst **lsta)
{
	int		w = 1;
	t_lst		*lstmp;

	lstmp = *lsta;

	while (w == 1)
	{
	w = 0;
	if((*lsta)->next)
	{
		if (ft_strcmp(((t_name*)(*lsta)->content)->name,((t_name*)((*lsta)->next)->content)->name) > 0)
		{
			swap(lsta);
		}
	}
	
	lstmp = (*lsta)->next;
	while(lstmp->next)
	{
		if (ft_strcmp(((t_name*)(lstmp)->content)->name,((t_name*)((lstmp)->next)->content)->name) > 0)
		{
			swap(&lstmp);
			w = 1;
		}
	}
	}

}
