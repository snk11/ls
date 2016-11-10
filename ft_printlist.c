/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 15:56:14 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"



/*

t_lsto	*ft_printlist32(t_lsto *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lsto	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		else if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->next;
	}
	lst2 = ft_lst_sort(lst2,croissant_time);
	lstbegio = lst2;
	return (lstbegio);
}
*/
