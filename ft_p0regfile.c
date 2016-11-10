/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0regfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:14:46 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 16:11:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


void	ft_p0regfile(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int	inderror;
	char	*s1;
	//	struct stat		sb;


	ind->indexyet = 0;

	s1 = NULL;
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
		ind->index1 = ft_getindex(lst1,lstcmd);
		if(ft_checkhyphencase(lstcmd,ind) == 1)
		{
			if(inderror == 1 && ind->indl == 1 && (ft_isreg(ft_makepath(".",(char*)(lst1->content))) || ft_islnk(ft_makepath(".",(char*)lst1->content))))
			{
				ft_printlregfile(lst1);
				ind->indregfile = 1;
			}
			else if(inderror == 1 && (ft_isreg(s1) || ft_islnk(s1))
				   )			{
				ft_putstr((char*)(lst1->content));
				ft_putstr("\n");
				ind->indregfile = 1;
			}
		}
		else if(ft_checkhyphencase(lstcmd,ind) == 0)
		{
			if(ind->index1 > 1 && inderror == 1 && ind->indl == 1 && (ft_isreg(ft_makepath(".",(char*)(lst1->content))) || ft_islnk(ft_makepath(".",s1))))
			{
				ft_printlregfile(lst1);
				ind->indregfile = 1;
			}
			else if(ind->index1 > 1 && inderror == 1 && (ft_isreg(s1) || ft_islnk(s1)))
			{
				ft_putstr((char*)(lst1->content));
				ft_putstr("\n");
				ind->indregfile = 1;
			}
			else if(inderror == 1 && ind->indl == 1 && (ft_isreg((char*)(lst1->content)) || ft_islnk(s1)))
			{
				ft_printlregfile(lst1);
				ind->indregfile = 1;
			}
			else if(inderror == 1 && (ft_isreg(s1) || ft_islnk(s1)))
			{
				ft_putstr((char*)(lst1->content));
				ft_putstr("\n");
				ind->indregfile = 1;
			}
		}
		lst1 = lst1->next;
	}

}
