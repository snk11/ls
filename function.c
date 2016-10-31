/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:43:19 by syusof            #+#    #+#             */
/*   Updated: 2016/10/31 23:53:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

/*
t_lst		*lst_add(t_lst *toplist, t_lst *lst1)
{
	t_lst	*lstmp;
	t_lst	*lst11;

	lst11 = NULL;
	if (toplist == NULL)
	{
		lst11 = ft_create_lst(lst1->content);
		((t_rep*)(lst11->content))->name = ft_memmove2(((t_rep*)(lst1->content))->name);
		((t_rep*)(lst11->content))->path = ft_memmove2(((t_rep*)(lst1->content))->path);
		toplist = lst11;
	}
	else
	{
		lstmp = toplist;
		if(ft_isdir(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name)) == 1)
		{
			while(lstmp->nextr)
				lstmp = lstmp->nextr;
			lst11 = ft_create_lst(lst1->content);
			((t_rep*)(lst11->content))->name = ft_memmove2(((t_rep*)(lst1->content))->name);
			((t_rep*)(lst11->content))->path = ft_memmove2(((t_rep*)(lst1->content))->path);
			lstmp->nextr = lst11;
		}
		else
		{
			while(lstmp->nextl)
				lstmp = lstmp->nextl;
			lst11 = ft_create_lst(lst1->content);
			((t_rep*)(lst11->content))->name = ft_memmove2(((t_rep*)(lst1->content))->name);
			((t_rep*)(lst11->content))->path = ft_memmove2(((t_rep*)(lst1->content))->path);
			lstmp->nextl = lst11;
		}
	}
	return (toplist);
	//		*t_lst1 = (*t_lst1)->next;
}
*/
void		lst_addo(t_lsto **toplist, t_lsto *lst1)
{

	t_lsto		*lstmp;
	char		*s1;
	char		*s2;

	s1 = NULL;
	s2 = NULL;
	lstmp = NULL;
	s1= ((t_rep*)(lst1->content))->name;
	s2= ((t_rep*)(lst1->content))->path;
	lstmp = ft_create_lsto((lst1)->content,s1,s2);
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

t_lsto		*lst_addo_down(t_lsto *toplist, t_lsto *lst1)
{

	t_lsto		*lstmp;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;
	char		*s1;
	char		*s2;

	s1 = NULL;
	s2 = NULL;

	lstmp = NULL;
	lstmp2 = NULL;
	lstbegi = NULL;
	lsttopbegi = toplist;
	while (lst1 && toplist)
	{
		s1= ((t_rep*)(lst1->content))->name;
		s2= ((t_rep*)(lst1->content))->path;
		lstmp = ft_create_lsto((lst1)->content,s1,s2);
		//		if (ind1 == 0)
		//		{
		//			lstmpbegi = lstmp;
		//			ind1 = 1;
		//		}
		//		if (ind1 == 1)
		{
			lstmp2 = lsttopbegi;
			while (lstmp2->next)
				lstmp2 = lstmp2->next;
			lstmp2->next = lstmp;
		}
		//		if (lstmp2 == NULL)
		//		{
		//			lstmp2 = lstmp;
		//			lstbegi = lstmp2;
		//		}
		//		else
		//			lstmp2->next = lstmp;
		lst1 = lst1->next;
	}
	if (lst1 && toplist == NULL)
	{
		s1= ((t_rep*)(lst1->content))->name;
		s2= ((t_rep*)(lst1->content))->path;
		lstmp = ft_create_lsto((lst1)->content,s1,s2);
		lsttopbegi = lstmp;
		lst1 = lst1->next;
		while(lst1)
		{
			s1= ((t_rep*)(lst1->content))->name;
			s2= ((t_rep*)(lst1->content))->path;
			lstmp = ft_create_lsto((lst1)->content,s1,s2);
			//		if (ind1 == 0)
			//		{
			//			lstmpbegi = lstmp;
			//			ind1 = 1;
			//		}
			//		if (ind1 == 1)
			{
				lstmp2 = lsttopbegi;
				while (lstmp2->next)
					lstmp2 = lstmp2->next;
				lstmp2->next = lstmp;
			}
			//		if (lstmp2 == NULL)
			//		{
			//			lstmp2 = lstmp;
			//			lstbegi = lstmp2;
			//		}
			//		else
			//			lstmp2->next = lstmp;
			lst1 = lst1->next;
		}
	}
	return (lsttopbegi);
	//		*t_lst1 = (*t_lst1)->next;
}

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
	while (lst1 && toplist)
	{
		lstmp = ft_create_lsto_char((lst1)->content);
		{
			lstmp2 = lsttopbegi;
			while (lstmp2->next)
				lstmp2 = lstmp2->next;
			lstmp2->next = lstmp;
		}
		lst1 = lst1->next;
	}
	if (lst1 && toplist == NULL)
	{
		lstmp = ft_create_lsto_char((lst1)->content);
		lsttopbegi = lstmp;
		lst1 = lst1->next;
		while(lst1)
		{
			lstmp = ft_create_lsto_char((lst1)->content);
			{
				lstmp2 = lsttopbegi;
				while (lstmp2->next)
					lstmp2 = lstmp2->next;
				lstmp2->next = lstmp;
			}
			lst1 = lst1->next;
		}
	}
	return (lsttopbegi);
}

t_lsto		*lst_addo_between(t_lsto *toplist, t_lsto *lst1)
{

	t_lsto		*lstmp;
	t_lsto		*lstmp2;
	t_lsto		*lstbegi;
	t_lsto		*lsttopbegi;
	char		*s1;
	char		*s2;

	s1 = NULL;
	s2 = NULL;

	lstmp = NULL;
	lstmp2 = NULL;
	lstbegi = NULL;
	lsttopbegi = toplist;
	lstmp2 = lsttopbegi;
	while (lst1 && toplist)
	{
		s1= ((t_rep*)(lst1->content))->name;
		s2= ((t_rep*)(lst1->content))->path;
		lstmp = ft_create_lsto((lst1)->content,s1,s2);
		lstmp->next = lstmp2->next;
		lstmp2->next = lstmp;
		lstmp2 = lstmp2->next;
		lst1 = lst1->next;
	}
	if (lst1 && toplist == NULL)
	{
		s1= ((t_rep*)(lst1->content))->name;
		s2= ((t_rep*)(lst1->content))->path;
		lstmp = ft_create_lsto((lst1)->content,s1,s2);
		lsttopbegi = lstmp;
		lst1 = lst1->next;
		while(lst1)
		{
			s1= ((t_rep*)(lst1->content))->name;
			s2= ((t_rep*)(lst1->content))->path;
			lstmp = ft_create_lsto((lst1)->content,s1,s2);
			{
				lstmp2 = lsttopbegi;
				while (lstmp2->next)
					lstmp2 = lstmp2->next;
				lstmp2->next = lstmp;
			}
			lst1 = lst1->next;
		}
	}
	return (lsttopbegi);
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
/*
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

	//				printf("fffffff%s\n",((t_rep*)(curlst->content))->path);
	return (curlst);
}
*/
t_lsto		*ft_create_lsto(void *content, char *s1, char *s2)
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
		((t_rep*)(curlst->content))->name = ft_memmove2(s1);
		((t_rep*)(curlst->content))->path = ft_memmove2(s2);
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
	{
		curlst->content = NULL;
	}
	else
	{
		curlst->content = ft_memmove2(content);
	}
	curlst->next = NULL;
	return (curlst);
}
