/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:01 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 00:34:55 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p1(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int inderror;
	t_lsto			*lst;
	t_lsto			*lstmp;
	t_lsto			*lstj;
	t_lsto *lst1begi;
	char *s1;

	lstmp = NULL;
	lst1begi = lst1;
	lst1 = lst1begi;
	s1 = NULL;

	lst1 = lst1begi;
//	while(lst1)
//	{
//		if (((char*)(lst1->content))[0] != '-' || ft_strcmp((char*)lst1->content,"-") == 0)
//			ind->indtotal++;
//		lst1 = lst1->next;
//	}
	lst1 = lst1begi;
	ind->indfirst = 0;
	ind->indexyet = 0;
	ind->indexyet2 = 0;
	ind->indexyet3 = 0;
	ind->indexyet4 = 0;
	while(lst1)
	{
		ind->index1 = ft_getindex(lst1,lstcmd);
		ind->indfirst++;
		inderror = 0;
		if (!opendir((char*)(lst1->content)))
		{
			//					ft_putstr_fd("ls: ", 2);
			//perror(strerror(ENOENT));
			//					perror(av[i]);
			inderror = 1;
		}
		if (inderror == 0 && ft_checkhyphen(lst1,lstcmd,ind) == 0)
		{
		//		printf("char = %s,index1 = %d\n",(char*)lst1->content,ind->index1);
			if (ind->indillegal != 0)
			{
			}
			else if (ind->indl == 1 && ind->indreverse == 1 && ind->indr == 1 && ind->inda == 1 && ind->indt == 1)
			{
				ft_printlatrreversedir((char*)(lst1->content), ind);
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
				ft_r((char*)(lst1->content),lstcmd, ind);
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
				ft_print_n((char*)lst1->content,lstcmd,ind);
				lst = ft_getreplist((char*)(lst1->content));
	//	printf("char = %s,option = %d,yet = %d,hyphen = %d\n",(char*)lst1->content,ind->indoption,ind->indexyet4,ft_checkhyphencase(lstcmd,ind));
					ft_printname((char*)lst1->content,lstcmd,ind);
				lstj = ft_printlist2(lst);
			}
		}
		lst1 = lst1->next;
	}
}
