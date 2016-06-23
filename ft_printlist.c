/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 11:46:17 by syusof            #+#    #+#             */
/*   Updated: 2016/06/23 13:16:22 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_printlist(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
//	lst2 = ft_lst_sort1(lst2);
	lst2 = ft_lst_sort(lst2,croissant);
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort1(lst1);
	lst1 = ft_lst_sort(lst1,croissant);
	while (lst1)
	{
		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist4(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort1(lst2);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort1(lst1);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

t_lsto	*ft_printlist2(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2, croissant);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, croissant);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	return (lstbegio);
}


t_lsto	*ft_printlist3(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
//		if(ft_isdir(lstmp) == 0)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort1(lst2);
//	while (lst1)
//	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
//		{
//			if(ft_strcmp(((t_rep*)((lst1))->content)->name, "lit.o") == 0)
//				printf("NIMP\n");
//			ft_putstr(((t_rep*)((lst1))->content)->name);
//			ft_putstr("\n");
//		}
//		lst1 = lst1->next;
//	}
	lstbegio = lst2;
//	while (lst2)
//	{
//		if ( (((t_rep*)(lst2)->content)->name)[0] != '.')
//		{
//			ft_putstr(((t_rep*)((lst2))->content)->name);
//			ft_putstr("\n");
//		}
//		lst2 = lst2->next;
//	}
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

t_lsto	*ft_getreplisto4(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
//		if(ft_isdir(lstmp) == 0)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort1(lst2);
	lstbegio = lst2;
//	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort1(lst1);
//	while (lst1)
//	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
//		{
//			if(ft_strcmp(((t_rep*)((lst1))->content)->name, "lit.o") == 0)
//				printf("NIMP\n");
//			ft_putstr(((t_rep*)((lst1))->content)->name);
//			ft_putstr("\n");
//		}
//		lst1 = lst1->next;
//	}
	return (lstbegio);
}

void	ft_printlist5(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
//	lst2 = ft_lst_sort3(lst2);
	lst2 = ft_lst_sort(lst2,decreasing);
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort3(lst1);
	lst1 = ft_lst_sort(lst1,decreasing);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist6(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;
//	struct stat		sa;
//	char			*s1;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
//	s1 = ft_memmove2(((t_rep*)(lst1)->content)->name);
//	stat(s1, &sa);
//	printf("s1 = %s \n",ctime(&(sa.st_mtime)));
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist7(t_lst *lstmp)
{

	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2,croissant);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1,croissant);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putstr(ft_ustoa(sb.st_nlink));
			ft_putstr(" ");
			ft_putstr(getpwuid(sb.st_uid)->pw_name);
			ft_putstr("  ");
			ft_putstr(getgrgid(sb.st_gid)->gr_name);
			ft_putstr("  ");
			ft_putstr(ft_lldtoa(sb.st_size));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

t_lsto	*ft_printlist8(t_lst *lstmp)
{
	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort1(lst2);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort1(lst1);
	while (lst1)
	{
		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putstr(ft_ustoa(sb.st_nlink));
			ft_putstr(" ");
			ft_putstr(getpwuid(sb.st_uid)->pw_name);
			ft_putstr("  ");
			ft_putstr(getgrgid(sb.st_gid)->gr_name);
			ft_putstr("  ");
			ft_putstr(ft_lldtoa(sb.st_size));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	return (lstbegio);
}

void	ft_printlist9(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;
//	struct stat		sa;
//	char			*s1;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
//	lst2 = ft_lst_sort4(lst2);
	lst2 = ft_lst_sort(lst2,croissant_time);
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort4(lst1);
	lst1 = ft_lst_sort(lst1,croissant_time);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
//	s1 = ft_memmove2(((t_rep*)(lst1)->content)->name);
//	stat(s1, &sa);
//	printf("s1 = %s \n",ctime(&(sa.st_mtime)));
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

t_lsto	*ft_printlist10(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
//	lst2 = ft_lst_sort1(lst2);
	lst2 = ft_lst_sort(lst2,decreasing_time);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
//	lst1 = ft_lst_sort1(lst1);
	lst1 = ft_lst_sort(lst1, decreasing_time);
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

t_lsto	*ft_printlist11(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2,decreasing_time);
	lstbegio = lst2;
	return (lstbegio);
}

t_lsto	*ft_printlist12(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2,decreasing);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	return (lstbegio);
}

void	ft_printlist13(t_lst *lstmp)
{

	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2, decreasing_time);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, decreasing_time);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putstr(ft_ustoa(sb.st_nlink));
			ft_putstr(" ");
			ft_putstr(getpwuid(sb.st_uid)->pw_name);
			ft_putstr("  ");
			ft_putstr(getgrgid(sb.st_gid)->gr_name);
			ft_putstr("  ");
			ft_putstr(ft_lldtoa(sb.st_size));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist14(t_lst *lstmp)
{

	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
//		if (ft_isdir(lstmp) == 1)
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2, decreasing);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, decreasing);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putstr(ft_ustoa(sb.st_nlink));
			ft_putstr(" ");
			ft_putstr(getpwuid(sb.st_uid)->pw_name);
			ft_putstr("  ");
			ft_putstr(getgrgid(sb.st_gid)->gr_name);
			ft_putstr("  ");
			ft_putstr(ft_lldtoa(sb.st_size));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

void	ft_printlist15(t_lst *lstmp)
{
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lst	*lstbegi;
//	struct stat		sa;
//	char			*s1;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort(lst2, croissant_time);
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort(lst1, croissant_time);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			ft_putstr(((t_rep*)((lst1))->content)->name);
//	s1 = ft_memmove2(((t_rep*)(lst1)->content)->name);
//	stat(s1, &sa);
//	printf("s1 = %s \n",ctime(&(sa.st_mtime)));
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
}

t_lsto	*ft_printlist16(t_lst *lstmp)
{
	struct stat		sb;
	t_lsto	*lst1;
	t_lsto	*lst2;
	t_lsto	*lstbegio;
	t_lst	*lstbegi;

	lst1 = NULL;
	lst2 = NULL;
	lstbegi = lstmp;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 0)
			lst_addo(&lst1, lstmp);
		lstmp = lstmp->nextl;
	}
	lstmp = lstbegi;
	while (lstmp)
	{
		if(ft_isdir(ft_makepath(((t_rep*)(lstmp->content))->path,((t_rep*)(lstmp->content))->name)) == 1)
			lst_addo(&lst2, lstmp);
		lstmp = lstmp->nextr;
	}
	lst2 = ft_lst_sort1(lst2);
	lstbegio = lst2;
	lst1 = lst_addo_down(lst1,lst2);
	lst1 = ft_lst_sort1(lst1);
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putstr(ft_ustoa(sb.st_nlink));
			ft_putstr(" ");
			ft_putstr(getpwuid(sb.st_uid)->pw_name);
			ft_putstr("  ");
			ft_putstr(getgrgid(sb.st_gid)->gr_name);
			ft_putstr("  ");
			ft_putstr(ft_lldtoa(sb.st_size));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_min));
			ft_putstr(" ");
			ft_putstr(ft_itoa((localtime(&(sb.st_ctime)))->tm_year));
			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}
	return (lstbegio);
}

