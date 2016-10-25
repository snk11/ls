/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:27:40 by syusof            #+#    #+#             */
/*   Updated: 2016/10/25 16:01:04 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_wl(t_lsto *lst1,t_loption loption)
{
	struct stat		sb;
	char	*linkname;
	int		l;
	ssize_t		r;

	l = 0;
	
	while (lst1)
	{
//		if ( (((t_rep*)(lst1)->content)->name)[0] != '.')
		{
			stat(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name), &sb);
			ft_print_permission(ft_makepath(((t_rep*)(lst1->content))->path,((t_rep*)(lst1->content))->name));
			ft_putstr("  ");
			ft_putwidth(ft_ustoa(sb.st_nlink),loption.link);
			ft_putstr(" ");
			ft_putwidth(getpwuid(sb.st_uid)->pw_name,loption.uname);
			ft_putstr("  ");
			ft_putwidth(getgrgid(sb.st_gid)->gr_name,loption.gname);
			ft_putstr("  ");
			ft_putwidth(ft_lldtoa(sb.st_size),loption.fsize);
			ft_putstr(" ");
			ft_putwidth(ft_itoa((localtime(&(sb.st_ctime)))->tm_mon),loption.month);
			ft_putstr(" ");
			ft_putwidth(ft_itoa((localtime(&(sb.st_ctime)))->tm_mday),loption.day);
			ft_putstr(" ");
			ft_putwidth(ft_itoa((localtime(&(sb.st_ctime)))->tm_hour),loption.hour);
			ft_putstr(" ");
			ft_putwidth(ft_itoa((localtime(&(sb.st_ctime)))->tm_min),loption.minute);
			ft_putstr(" ");
			ft_putwidth(ft_itoa((localtime(&(sb.st_ctime)))->tm_year + 1900),loption.year);
			ft_putstr(" ");
//			ft_putulongnbr(sb.st_blocks);
//			l = l + sb.st_blocks;
//			ft_putstr(" ");
			ft_putstr(((t_rep*)((lst1))->content)->name);
			linkname = malloc(sb.st_size + 1);
			r = readlink(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name),linkname,sb.st_size + 1);
			if(ft_islnk(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name )))
			{
				ft_putstr(" -> ");
				//readlink("f",linkname,PATH_MAX);
//				readlink(ft_makepath(((t_rep*)lst1->content)->path,((t_rep*)lst1->content)->name),linkname,);
				if(linkname)
					ft_putstr(linkname);
			}
			ft_putstr("\n");
		}
		lst1 = lst1->next;
	}

}
