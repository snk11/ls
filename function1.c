/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:38:40 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 22:52:25 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		lst_addo(t_lsto **toplist, t_lsto **lst1)
{
	t_lsto		*lstmp;

	lstmp = NULL;
	lstmp = ft_create_lsto2((t_rep*)(*lst1)->content);
//	ft_lst_fullfield(lst1, &lstmp);
	if (*toplist == NULL)
		*toplist = lstmp;
	else
	{
		lstmp->next = *toplist;
		*toplist = lstmp;
	}
}

void		lst_addo1(t_lsto ***toplist, t_lsto *lst1)
{
	t_lsto		*lstmp;

	lstmp = NULL;
	lstmp = ft_create_lsto2((t_rep*)(lst1)->content);
//	ft_lst_fullfield(lst1, &lstmp);
	if (**toplist == NULL)
		**toplist = lstmp;
	else
	{
		lstmp->next = **toplist;
		**toplist = lstmp;
	}
}

t_lsto		*lst_addo_down(t_lsto *toplist, t_lsto *lst1)
{
//	t_lsto		*lstmp;
//	t_lsto		*lstmp2;
//	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;

//	lstmp = NULL;
//	lstmp2 = NULL;
//	lstbegi = NULL;
	lsttopbegi = toplist;
	lsttopbegi = lst_addo_down_p1(&lst1, &lsttopbegi);
	lsttopbegi = lst_addo_down_p2(&lst1, &lsttopbegi);
	return (lsttopbegi);
}

t_lsto		*lst_addo_down_p1(t_lsto **lst1, t_lsto **lsttopbegi)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = NULL;
	while (*lst1 && *lsttopbegi)
	{
		lstmp = ft_create_lsto2((t_rep*)(*lst1)->content);
//		ft_lst_fullfield(*lst1, &lstmp);
		lstmp2 = *lsttopbegi;
		while (lstmp2->next)
			lstmp2 = lstmp2->next;
		lstmp2->next = lstmp;
		*lst1 = (*lst1)->next;
	}
	return (*lsttopbegi);
}

t_lsto		*lst_addo_down_p2(t_lsto **lst1, t_lsto **lsttopbegi)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = NULL;
	if (*lst1 && *lsttopbegi == NULL)
	{
		lstmp = ft_create_lsto2((t_rep*)(*lst1)->content);
//		ft_lst_fullfield(*lst1, &lstmp);
		*lsttopbegi = lstmp;
		*lst1 = (*lst1)->next;
		while (*lst1)
		{
			lstmp = ft_create_lsto2((*lst1)->content);
//			ft_lst_fullfield(*lst1, &lstmp);
			lstmp2 = *lsttopbegi;
			while (lstmp2->next)
				lstmp2 = lstmp2->next;
			lstmp2->next = lstmp;
			*lst1 = (*lst1)->next;
		}
	}
	return (*lsttopbegi);
}
