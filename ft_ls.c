/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/05/23 04:40:13 by syusof           ###   ########.fr       */
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
	t_lsto			*lstj;
	int				i;
	int				inderror;

	lst = NULL;
	lstj = NULL;
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
			while (lsti)
			{
				ft_putstr("\n");
				printf("%s:\n",ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
				if (lst)
				{
					lstj = ft_printlist2(lst);
					lsti = lst_addo_down(lsti,lstj);
					lsti = ft_lst_sort(lsti,croissant_pathname);
				}
				lsti = lsti->next;
			}
		}
		//else
		/*
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
	}


	return (0);
}
