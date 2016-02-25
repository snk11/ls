/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trailrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 04:30:10 by syusof            #+#    #+#             */
/*   Updated: 2016/02/25 08:40:57 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_trailrep(t_lst **lst,char *str)
{
	t_lst	*lst1;
	t_lst	*lstname;
	t_lst	*lstmp2;
	t_name	*e1;
	t_rep	*e2;
	struct stat		sb;
	int		ret;
	int		ind1;
	struct dirent	*pdirent1;
	DIR				*pdir1;

	lst1 = 0;
	lstname = 0;
	lstmp2 = 0;
	ret = 0;
	ind1 = 0;
	e2 = 0;
	/*
	e1 = (t_name*)malloc(sizeof(t_name));
	e1->name = str;
	lstmp2 = create_lst(e1);
	lst_add1(&lstname, lstmp2);
	*/
	e2 = (t_rep*)malloc(sizeof(t_rep));
	lstmp2 = create_lst(e2);
	((t_rep*)(lstmp2)->content)->path = str;
							ft_putstr("path =");
							ft_putstr(((t_rep*)(lstmp2)->content)->path);
							ft_putstr("\n");
	lst_add1(lst, lstmp2);
//	lst1 = ft_getreplist(str);
	pdir1 = opendir(str);
	while((pdirent1 = readdir(pdir1)))
	{
							ft_putstr(pdirent1->d_name);
							ft_putstr("\n");
//		if (((t_name*)(lst1)->content)->name[0] != '.')
		if ((pdirent1->d_name)[0] != '.')
		{
			ret++;
//			((t_rep*)(*lst)->content)->name = ((t_rep*)(lst1)->content)->name;
//			((t_rep*)(*lst)->content)->val = ret;
//			stat(((t_name*)(lst1)->content)->name,&sb);
			if(stat(pdirent1->d_name,&sb) == 0 && S_ISDIR(sb.st_mode))
			{
							ft_putstr("name =");
//							ft_putstr(((t_name*)(lst1)->content)->name);
							ft_putstr(pdirent1->d_name);
							ft_putstr("\n");
//				ft_trailrep(lst,ft_makepath(str,((t_name*)(lst1)->content)->name));
				ft_trailrep(lst,ft_makepath(str,pdirent1->d_name));
//				((t_rep*)(*lst)->content)->path = ft_makepath(((t_name*)(lstname)->content)->name,((t_name*)(lst1)->content)->name);
//				e1->name = ft_makepath(((t_name*)(lstname)->content)->name,((t_name*)(lst1)->content)->name);
//				lstmp2 = create_lst(e1);
//				lst_add1(&lstname, lstmp2);
			}
		}
//			else
//				((t_rep*)(*lst)->content)->path = ((t_name*)(lstname)->content)->name;

//		lst1 = lst1->next;
	}
	closedir(pdir1);
	((t_rep*)(*lst)->content)->val = ret;
}
