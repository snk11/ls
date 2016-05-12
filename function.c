/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:43:19 by syusof            #+#    #+#             */
/*   Updated: 2016/05/12 13:52:21 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void		lst_add1(t_lst **toplist, t_lst *t_lst1)
{

	t_lst		*lstmp;

	lstmp = NULL;
	lstmp = create_lst((t_lst1)->content);
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
		lst->next = create_lst((*lstmp)->content);
		*lstmp = (*lstmp)->next;
	}
//						ft_putstr("pushback = ");
//						ft_putstr(((t_name*)(lst->next)->content)->name);
//						ft_putstr("\n");
}


t_lst		*create_lst1(void *content)
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
	curlst->next = NULL;
	return (curlst);
}




