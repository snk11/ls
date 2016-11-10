/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 15:51:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"



t_lsto	*ft_printlist29(t_lsto *lstmp)
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
//	lst2 = ft_lst_sort1(lst2);
	lst2 = ft_lst_sort(lst2,croissant_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort1(lst1);
	lst1 = ft_lst_sort(lst1, croissant_time);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
//			if(ft_strcmp(((t_rep*)((lst1))->content)->name, "lit.o") == 0)
//				printf("NIMP\n");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	/*
	lst2 = lstbegio;
	while (lst2)
	{
		ft_getreplist(((t_rep*)(lst2->content))->path);
		lst2 = lst2->next;
	}
	*/
	return (lstbegio);
}

t_lsto	*ft_printlist30(t_lsto *lstmp)
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


t_lsto	*ft_printlist31(t_lsto *lstmp)
{
	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lsto	*lstbegi;
	t_lsto	*lstmp2;
	unsigned long l;
	t_loption	loption;
	ssize_t		r;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	lstmp2 = NULL;
	l = 0;

	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		else if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->next;
	}
//	lst2 = ft_lst_sort1(lst2);
	lst2 = ft_lst_sort(lst2,croissant_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort1(lst1);
	lst1 = ft_lst_sort(lst1, croissant_time);

	lstmp2 = lst1;
	while (lstmp2)
	{
			if(lstat(ft_makepath(((t_rep*)(lstmp2->content))->path,((t_rep*)(lstmp2->content))->name), &sb) == 0)
				l = l + sb.st_blocks;
			lstmp2 = lstmp2->next;
	}
	ft_putstr("total ");
	ft_putulongnbr(l);
	ft_putstr("\n");
	ft_init2(&loption);
	ft_width(lst1,&loption);
	ft_wl(lst1,loption);

	return (lstbegio);
}
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
