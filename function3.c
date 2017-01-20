/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:19:47 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 21:17:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*lst_addo_between(t_lsto *toplist, t_lsto *lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;

	lstmp = NULL;
	lstmp2 = NULL;
	lstbegi = NULL;
	lsttopbegi = toplist;
	lstmp2 = lsttopbegi;
	lst_addo_between_p1(toplist, &lst1);
	lsttopbegi = lst_addo_between_p2(&lsttopbegi, &lst1);
	return (lsttopbegi);
}

void		lst_addo_between_p1(t_lsto *toplist, t_lsto **lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = toplist;
	while (*lst1 && toplist)
	{
		lstmp = ft_create_lsto2((t_rep*)(*lst1)->content);
//		ft_lst_fullfield(*lst1, &lstmp);
		lstmp->next = lstmp2->next;
		lstmp2->next = lstmp;
		lstmp2 = lstmp2->next;
		*lst1 = (*lst1)->next;
	}
}

t_lsto		*lst_addo_between_p2(t_lsto **lsttopbegi, t_lsto **lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = *lsttopbegi;
	if (*lst1 && *lsttopbegi == NULL)
	{
		lstmp = ft_create_lsto2((t_rep*)(*lst1)->content);
//		ft_lst_fullfield(*lst1, &lstmp);
		*lsttopbegi = lstmp;
		*lst1 = (*lst1)->next;
		lst_addo_between_p2_p1(&lsttopbegi, &lst1);
	}
	return (*lsttopbegi);
}

void		lst_addo_between_p2_p1(t_lsto ***lsttopbegi, t_lsto ***lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = **lsttopbegi;
	while (**lst1)
	{
		lstmp = ft_create_lsto2((t_rep*)(**lst1)->content);
//		ft_lst_fullfield(**lst1, &lstmp);
		{
			lstmp2 = **lsttopbegi;
			while (lstmp2->next)
				lstmp2 = lstmp2->next;
			lstmp2->next = lstmp;
		}
		**lst1 = (**lst1)->next;
	}
}
