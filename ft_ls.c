/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/05/24 14:15:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
//# include "push_swap/push_swap.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_lst			*lst;
	t_lsto			*lsti;
	t_lsto			*lstibegi;
	t_lsto			*lstj;
	int				i;
	int				inderror;

	lst = NULL;
	lstj = NULL;
	lstibegi = NULL;
	i = 1;
	inderror = 0;

	if (!av[1])
	{
		lst = ft_getreplist(".");

//		while (lst)
//		{
//			printf("%s\n",((t_rep*)(lst->content))->name);
//			lst = lst->nextl;
//		}
		ft_printlist(lst);
	}
	else if(av[i])
	{
		while(av[i])
		{
			if (ft_strcmp(av[i], "-1") != 0 && ft_strcmp(av[i], "--") != 0 && ft_strcmp(av[i], "-1R") != 0)
			{
				ft_putstr_fd("ls: ", 2);
				opendir(av[i]);
				//perror(strerror(ENOENT));
				perror(av[i]);
				inderror = 1;
			}
			i++;
		}
		if (inderror == 0 && (ft_strcmp(av[1], "-1") == 0 || ft_strcmp(av[1], "--") == 0))
		{
			lst = ft_getreplist(".");
			ft_printlist(lst);
		}
		if (inderror == 0 && (ft_strcmp(av[1], "-1R")== 0 || ft_strcmp(av[1], "-1R")== 0))
		{
			lst = ft_getreplist(".");
			lsti = ft_printlist2(lst);
			lstibegi = lsti;
			while (lsti)
			{
//				ft_putstr("R ");
//				ft_putstr(((t_rep*)(lsti->content))->name);
//				ft_putstr("\n");
				stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
				if((sb.st_mode & S_IRUSR))
					lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				if(lst && (sb.st_mode & S_IRUSR))
				{
					lstj = ft_printlist3(lst);
					lsti = lst_addo_down(lsti,lstj);
//					lsti = ft_lst_sort(lsti,croissant_pathname);
				}
				lsti = lsti->next;
				lst = NULL;
			}
			lstibegi = ft_lst_sort2(lstibegi);
			lsti = lstibegi;
			while (lsti)
			{
				ft_putstr("\n");
				ft_putstr(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				ft_putstr(":\n");
				stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
				if((sb.st_mode & S_IRUSR))
					lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				if(lst)
					lstj = ft_printlist2(lst);
				else if ((sb.st_mode & S_IRUSR) == 0)
				{
					ft_putstr_fd("ls: ", 2);
					opendir(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				//perror(strerror(ENOENT));
					perror(((t_rep*)(lsti->content))->name);
				}
				lsti = lsti->next;
				lst = NULL;
			}
		}
	}
	/*
		//else
		{
			stat(av[1], &sb);
			{
				if(S_ISDIR(sb.st_mode))
					printf("d\n");
				if(sb.st_mode & S_IRUSR)
				{
					printf("r\n");
				}
				printf("%d\n",sb.st_nlink);

				printf("%s\n",getpwuid(sb.st_uid)->pw_name);
				printf("%s\n",getgrgid(sb.st_gid)->gr_name);
				printf("%lld\n",sb.st_size);
			//		printf("%s\n",ctime(&(sb.st_ctime)));

				printf("%d\n",(localtime(&(sb.st_ctime)))->tm_mon);
				printf("%d\n",(localtime(&(sb.st_ctime)))->tm_mday);
				printf("%d\n",(localtime(&(sb.st_ctime)))->tm_hour);
				printf("%d\n",(localtime(&(sb.st_ctime)))->tm_min);
				printf("%d\n",(localtime(&(sb.st_ctime)))->tm_year);
			}
		}
*/

	return (0);
}
