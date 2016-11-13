/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:51:30 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 09:40:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		croissant(t_lsto *lsta)
{
	return (ft_strcmp(((t_rep*)(lsta)->content)->name,
				((t_rep*)((lsta)->next)->content)->name) <= 0);
}

int		croissant_char(t_lsto *lsta)
{
	return (ft_strcmp(lsta->content, (lsta->next)->content) <= 0);
}

int		decreasing(t_lsto *lsta)
{
	return (ft_strcmp(((t_rep*)(lsta)->content)->name,
				((t_rep*)((lsta)->next)->content)->name) > 0);
}

int		decreasing_char(t_lsto *lsta)
{
	return (ft_strcmp(lsta->content, (lsta->next)->content) > 0);
}
