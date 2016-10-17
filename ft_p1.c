/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:01 by syusof            #+#    #+#             */
/*   Updated: 2016/10/17 18:24:09 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p1(t_lsto *lst1,t_ind *ind)
{
	int inderror;
	t_lsto			*lst;
	t_lsto			*lstj;
	t_lsto *lst1begi;
	char *s1;

	lst1begi = lst1;
	lst1 = lst1begi;
	s1 = NULL;

	lst1 = lst1begi;
	while(lst1)
	{
		if (((char*)(lst1->content))[0] != '-' || ft_strcmp((char*)lst1->content,"-") == 0)
			ind->indtotal++;
		lst1 = lst1->next;
	}
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
				if(ft_strcmp((char*)(lst1->content),"-") == 0)
				{
					ft_putstr_fd("ls: ", 2);
					perror((char*)(lst1->content));
				}
				else if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0)))
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
//		if(lst1)
//			printf("lst1 = %s\n",((char*)(lst1->content)));
//		printf("inderror = %d\n",inderror);
		if(inderror == 1 && ind->indl == 1 && ft_isreg((char*)(lst1->content)))
		{
			ft_printlregfile((char*)(lst1->content));
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
			ind->indfirst++;
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
				if (ind->indfirst > 1)
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
