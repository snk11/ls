/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:43:19 by syusof            #+#    #+#             */
/*   Updated: 2016/05/15 16:39:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void		lst_add(t_lst **toplist, t_lst *lst1)
{
	t_lst	*lstmp;
	t_lst	*lst11;

	lst11 = NULL;
	if (*toplist == NULL)
	{
		*toplist = lst1;
	}
	else
	{
		lstmp = *toplist;
		if(ft_isdir(lst1))
		{
			while(lstmp->nextr)
				lstmp = lstmp->nextr;
			lst11 = ft_create_lst(lst1->content);
			lstmp->nextr = lst11;
		}
		else
		{
			while(lstmp->nextl)
				lstmp = lstmp->nextl;
			lst11 = ft_create_lst(lst1->content);
			lstmp->nextl = lst11;
		}
	}
	//		*t_lst1 = (*t_lst1)->next;
}

void		lst_addo(t_lsto **toplist, t_lst *t_lst1)
{

	t_lsto		*lstmp;

	lstmp = NULL;
	lstmp = ft_create_lsto((t_lst1)->content);
	if (*toplist == NULL)
	{
		*toplist = lstmp;
	}
	else
	{
		lstmp->next = *toplist;
		*toplist = lstmp;
	}
	//		*t_lst1 = (*t_lst1)->next;
}
/*
void	ft_push1stback(t_lst **lstmp)
{
	t_lst	*lst;

	lst = NULL;
	lst = *lstmp;
	if ((*lstmp)->content)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		lst->next = ft_create_lst((*lstmp)->content);
		*lstmp = (*lstmp)->next;
	}
}
*/

t_lst		*ft_create_lst(void *content)
{
	t_lst	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		if (!(curlst->content = malloc(sizeof(content))))
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
	}
	curlst->nextl = NULL;
	curlst->nextr = NULL;
	return (curlst);
}

t_lsto		*ft_create_lsto(void *content)
{
	t_lsto	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lsto*)malloc(sizeof(t_lsto))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		if (!(curlst->content = malloc(sizeof(content))))
			return (NULL);
		curlst->content = ft_memmove(curlst->content, content, sizeof(content));
	}
	curlst->next = NULL;
	return (curlst);
}



