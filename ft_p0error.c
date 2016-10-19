/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:31:27 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 13:57:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int		inderror;
	char	*s1;
	

	ind->indexyet = 0;
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
		if(ft_checkhyphencase(lst1,ind) == 1 && ind->indexyet == 0)
		{
			ind->indexyet = 1;
		}
		else if(inderror == 1 && !ft_isreg((char*)lst1->content))
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
				ind->inderror = 1;
			}
			else if (ind->ind1 == 0 && !ft_isreg(s1))
			{
				if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0 || ft_strcmp((char*)lst1->content,"--") == 0)))
//				if ((!opendir((char*)(lst1->content)) && ind->indoption == 0))
//				if(ft_strcmp((char*)(lst1->content),"-") == 0)
				{
					ft_putstr_fd("ls: ", 2);
					ft_putstr_fd((char*)(lst1->content), 2);
					ft_putstr_fd(": ", 2);
					ft_putstr_fd(strerror(errno),2);
					ft_putstr_fd("\n", 2);
//					perror((char*)(lst1->content));
				}
//				else if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0)))
				{
//					ft_putstr_fd("ls: ", 2);
//					ft_putstr_fd((char*)(lst1->content), 2);
//					ft_putstr_fd(": ", 2);
//					ft_putstr_fd(strerror(errno),2);
//					ft_putstr_fd("\n", 2);
//					perror((char*)(lst1->content));
				}
				ind->inderror = 1;
			}
		}
		lst1 = lst1->next;
	}
}
