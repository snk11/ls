/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:08:40 by syusof            #+#    #+#             */
/*   Updated: 2016/11/11 12:19:48 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_mem1(char **s1, char **s2, t_lsto *lsta)
{
	*s1 = ft_memmove2(ft_makepath(((t_rep*)(lsta->content))->path,((t_rep*)(lsta->content))->name));
	*s2 = ft_memmove2(ft_makepath(((t_rep*)((lsta->next)->content))->path,((t_rep*)((lsta->next)->content))->name));
}

void		ft_mem1_char(char **s1, char **s2, t_lsto *lsta)
{
	*s1 = ft_memmove2(lsta->content);
	*s2 = ft_memmove2((lsta->next)->content);
}
