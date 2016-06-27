/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/06/27 15:27:13 by syusof           ###   ########.fr       */
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
	t_lsto			*lst1;
	t_lsto			*lst1begi;
	int				i;
	int				inderror;
	t_ind			*ind;
	int j;
	char 			*s1;

	ind = NULL;
	ind = (t_ind*)malloc(sizeof(t_ind));
	lst = NULL;
	lstj = NULL;
	lst1 = NULL;
	lstibegi = NULL;
	lst1begi = NULL;
	i = 1;
	inderror = 0;
	ft_init(ind);
	lst1 = ft_getprimelist(av);
	lst1begi = lst1;
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
	else if(av[2])
	{
//		ft_scan_ind(av,ind);
		ft_scan_option(av,ind);
//		ft_printerror(av,ind);
		j = 1;


		lst1 = lst1begi;
		while(lst1)
		{
			inderror = 0;
			ind->ind1 = 0;
			{
				if (!opendir((char*)(lst1->content)))
				{
					inderror = 1;
				}
			}
			if (inderror == 1)
			{
				s1 = ft_memmove2((char*)(lst1->content));
				if (ind->indillegal != 0 && ind->ind1 == 0)
				{
					
					ft_putstr_fd("ls: ", 2);
					ft_putstr_fd("illegal option -- ", 2);
					ft_putchar_fd(ind->indillegal, 2);
					ft_putstr_fd("\n", 2);
					ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n",2);
					ind->ind1 = 1;
				}
				else if (ind->ind1 == 0 && !ft_isreg(s1))
				{
					if (!opendir((char*)(lst1->content)) && ((char*)(lst1->content))[0] != '-')
					{
						ft_putstr_fd("ls: ", 2);
						perror((char*)(lst1->content));
					}
				}
			}
			lst1 = lst1->next;
		}
		lst1 = lst1begi;
		while(lst1)
		{
			s1 = ft_memmove2((char*)(lst1->content));
			inderror = 0;
			{
				if (!opendir((char*)(lst1->content)))
				{
					inderror = 1;
				}
			}
			if(inderror == 1 && ind->indl == 1 && ft_isreg((char*)(lst1->content)))
			{
				ft_printlreg((char*)(lst1->content));
			}
			else if(inderror == 1 && ft_isreg(s1))
			{
				ft_putstr((char*)(lst1->content));
				ft_putstr("\n");
			}
			lst1 = lst1->next;
		}
		lst1 = lst1begi;
		while(lst1)
		{
			if (((char*)(lst1->content))[0] != '-')
				ind->indfirst++;
			inderror = 0;
//			if (ft_check_string(av[i]))
			{
				if (!opendir((char*)(lst1->content)))
				{
//					ft_putstr_fd("ls: ", 2);
				//perror(strerror(ENOENT));
//					perror(av[i]);
					inderror = 1;
				}
				
//				if (ind->indl == 1)
//				{
//					ft_printlreg(av[i]);
//					ft_printldir(av[i],ind);
//					ft_printlrdir(av[i],ind);
//				}
			}
//			if (inderror == 0 && ft_check_string(av[i]))
			if (inderror == 0)
			{
//				printf("i = %d, indfirst = %d\n",i,ind.indfirst);
				if (ind->indillegal != 0)
				{
				}

				else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
				{
					ft_atrreverse((char*)(lst1->content), ind);
				}
				else if (ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indl == 1)
				{
					ft_printlarreversedir((char*)(lst1->content), ind);
				}
				else if (ind->indreverse == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
				{
					ft_printltrreversedir((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indr == 1 && ind->indt == 1 && ind->indl == 1)
				{
					ft_printlartdir((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indreverse == 1 && ind->indt == 1 && ind->indl == 1)
				{
					ft_printlatreversedir((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indreverse == 1 && ind->indt == 1)
				{
					ft_atreverse((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indr == 1 && ind->indreverse == 1)
				{
					ft_arreverse((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indr == 1 && ind->indt == 1)
				{
					ft_art((char*)(lst1->content), ind);
				}
				else if (ind->indreverse == 1 && ind->indr == 1 && ind->indt == 1)
				{
					ft_trreverse((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indr == 1 && ind->indl == 1)
				{
					ft_printlardir((char*)(lst1->content), ind);
				}
				else if (ind->indt == 1 && ind->indr == 1 && ind->indl == 1)
				{
					ft_printlrtdir((char*)(lst1->content), ind);
				}
				else if (ind->indreverse == 1 && ind->indr == 1 && ind->indl == 1)
				{
					ft_printlrreversedir((char*)(lst1->content), ind);
				}
				else if (ind->indt == 1 && ind->inda == 1 && ind->indl == 1)
				{
					ft_printlatdir((char*)(lst1->content), ind);
				}
				else if (ind->indt == 1 && ind->indreverse == 1 && ind->indl == 1)
				{
					ft_printltreversedir((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indreverse == 1 && ind->indl == 1)
				{
					ft_printlareversedir((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indreverse == 1)
				{
					ft_areverse((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indt == 1)
				{
					ft_at((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indr == 1)
				{
					ft_ar((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1 && ind->indl == 1)
				{
					ft_printladir((char*)(lst1->content), ind);
				}
				else if (ind->indr == 1 && ind->indt == 1)
				{
					ft_rt((char*)(lst1->content), ind);
				}
				else if (ind->indr == 1 && ind->indreverse == 1)
				{
					ft_rreverse((char*)(lst1->content), ind);
				}
				else if (ind->indl == 1 && ind->indr == 1)
				{
					ft_printlrdir((char*)(lst1->content), ind);
				}
				else if (ind->indl == 1 && ind->indt == 1)
				{
					ft_printltdir((char*)(lst1->content), ind);
				}
				else if (ind->indl == 1 && ind->indreverse == 1)
				{
					ft_printlreversedir((char*)(lst1->content), ind);
				}
				else if (ind->indt == 1 && ind->indreverse == 1)
				{
					ft_treverse((char*)(lst1->content), ind);
				}
				else if (ind->indl == 1)
				{
					ft_printldir((char*)(lst1->content),ind);
				}
				else if (ind->indr == 1)
				{
					ft_r((char*)(lst1->content), ind);
				}
				else if (ind->inda == 1)
				{
					ft_a((char*)(lst1->content), ind);
				}
				else if (ind->indt == 1)
				{
					ft_t((char*)(lst1->content), ind);
				}
				else if (ind->indreverse == 1)
				{
					ft_reverse((char*)(lst1->content), ind);
				}
				else
				{
//					if ( (i > 1 && (ind.indfirst == 1 && i > 2)) || (i > 1 && ind.indfirst == 0))
					if (ind->indfirst > 1)
						ft_putstr("\n");
							lst = ft_getreplist((char*)(lst1->content));
							if (av[3] || ind->indfirst > 1)
							{
								ft_putstr((char*)(lst1->content));
								ft_putstr(":\n");
							}
							lstj = ft_printlist2(lst);
				}
			}
			lst1 = lst1->next;
		}
	}
	else if(av[1])
	{
			ft_scan_option(av,ind);
			//if (ft_strcmp(av[1], "-1") != 0 && ft_strcmp(av[1], "--") != 0 && ft_strcmp(av[1], "-1R") != 0 && ft_strcmp(av[1],"-1a") != 0 && ft_strcmp(av[1],"-1r") != 0 && ft_strcmp(av[1],"-1t") != 0)
			if (ft_check_string(av[1]))
			{
				if (!opendir(av[1]))
				{
					if(!ft_isreg(av[1]))
					{
						ft_putstr_fd("ls: ", 2);
				//perror(strerror(ENOENT));
						perror(av[1]);
					}
					else
					{
						ft_putstr(av[1]);
						ft_putstr("\n");
					}
					inderror = 1;
				}
			}
			//if (inderror == 0 && (ft_strcmp(av[1], "-1") != 0 && ft_strcmp(av[1], "--") != 0 && ft_strcmp(av[1],"-1R") != 0 && ft_strcmp(av[1],"-1a") != 0 && ft_strcmp(av[1],"-1r") != 0 && ft_strcmp(av[1],"-1t") != 0))
			if (inderror == 0 && ft_check_string(av[1]))
			{
//				if (lst = ft_getreplist();
				
				
//				lst = ft_getreplist(".");
//				lsti = ft_getreplisto4(lst);
//				while (lsti)
//				{
//					if (ft_strcmp(av[1],((t_rep*)(lsti->content))->name) == 0)
					{
//						lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
						lst = ft_getreplist(av[1]);
						lstj = ft_printlist2(lst);
					}
//					lsti = lsti->next;
//				}
			}
			else if (inderror == 0 && (ft_strcmp(av[1], "-1") == 0 || ft_strcmp(av[1], "--") == 0))
			{
				lst = ft_getreplist(".");
				ft_printlist(lst);
			}
			else if (inderror == 0 && (ft_strcmp(av[1],"-1t")) == 0)
			{
				lst = ft_getreplist(".");
				ft_printlist6(lst);
			}
			else if (inderror == 0 && (ft_strcmp(av[1],"-1r")) == 0)
			{
				lst = ft_getreplist(".");
				ft_printlist5(lst);
			}
			else if (inderror == 0 && (ft_strcmp(av[1],"-1a")) == 0)
			{
				lst = ft_getreplist4(".");
				ft_printlist4(lst);
			}
			else if (inderror == 0 && (ft_strcmp(av[1], "-1R")) == 0)
			{
				lst = ft_getreplist(".");
				lsti = ft_printlist2(lst);
				lstibegi = lsti;
				while (lsti)
				{
//					ft_putstr("R ");
//					ft_putstr(((t_rep*)(lsti->content))->name);
//					ft_putstr("\n");
					stat(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name),&sb);
					if((sb.st_mode & S_IRUSR))
						lst = ft_getreplist(ft_makepath(((t_rep*)(lsti->content))->path,((t_rep*)(lsti->content))->name));
					if(lst && (sb.st_mode & S_IRUSR))
					{
						lstj = ft_printlist3(lst);
						lsti = lst_addo_down(lsti,lstj);
//						lsti = ft_lst_sort(lsti,croissant_pathname);
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
