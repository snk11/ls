/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:07:41 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 15:12:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsto		*lst_addo_down_char(t_lsto *toplist, t_lsto *lst1)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;

	lstmp = NULL;
	lstmp2 = NULL;
	lstbegi = NULL;
	lsttopbegi = toplist;
	lsttopbegi = lst_addo_down_char_p1(&lst1, &lsttopbegi);
	lsttopbegi = lst_addo_down_char_p2(&lst1, &lsttopbegi);
	return (lsttopbegi);
}

t_lsto		*lst_addo_down_char_p1(t_lsto **lst1, t_lsto **lsttopbegi)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = NULL;
	while (*lst1 && *lsttopbegi)
	{
		lstmp = ft_create_lsto_char((*lst1)->content);
		lstmp2 = *lsttopbegi;
		while (lstmp2->next)
			lstmp2 = lstmp2->next;
		lstmp2->next = lstmp;
		*lst1 = (*lst1)->next;
	}
	return (*lsttopbegi);
}

t_lsto		*lst_addo_down_char_p2(t_lsto **lst1, t_lsto **lsttopbegi)
{
	t_lsto		*lstmp;
	t_lsto		*lstmp2;

	lstmp = NULL;
	lstmp2 = NULL;
	if (*lst1 && *lsttopbegi == NULL)
	{
		lstmp = ft_create_lsto_char((*lst1)->content);
		*lsttopbegi = lstmp;
		*lst1 = (*lst1)->next;
		while (*lst1)
		{
			lstmp = ft_create_lsto((*lst1)->content);
			lstmp2 = *lsttopbegi;
			while (lstmp2->next)
				lstmp2 = lstmp2->next;
			lstmp2->next = lstmp;
			*lst1 = (*lst1)->next;
		}
	}
	return (*lsttopbegi);
}

t_lsto		*ft_create_lsto(t_rep *e)
{
	t_lsto	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lsto*)malloc(sizeof(t_lsto))))
		return (NULL);
	if (e == NULL)
		curlst->content = NULL;
	else
	{
		curlst->content = (t_rep*)malloc(sizeof(t_rep));
		((t_rep*)(curlst->content))->path = ft_memmove2(e->path);
		((t_rep*)(curlst->content))->name = ft_memmove2(e->name);
		((t_rep*)(curlst->content))->val = e->val;
	}
	curlst->next = NULL;
	return (curlst);
}

t_lsto		*ft_create_lsto_char(char *content)
{
	t_lsto	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lsto*)malloc(sizeof(t_lsto))))
		return (NULL);
	if (content == NULL)
		curlst->content = NULL;
	else
	{
		curlst->content = ft_memmove2(content);
	}
	curlst->next = NULL;
	return (curlst);
}
