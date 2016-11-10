/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:29:22 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 20:38:41 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error_p1(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int		inderror;
	char	*s1;

	inderror = 0;
	ind->ind1 = 0;
	if (!opendir((char*)(lst1->content)))
	{
		inderror = 1;
	}
	if(inderror == 1 && !ft_isreg(ft_makepath(".",(char*)lst1->content)) && !ft_islnk(ft_makepath(".",(char*)lst1->content)))
		ft_p0error_p1_p1(lst1, ind);
	else if(ft_checkhyphencase(lstcmd,ind) == 1 &&  ind->indoption > 0 && ind->indexyet == 0 && ft_strcmp((char*)lst1->content,"--") == 0)
	{
		ind->indexyet = 1;
	}
	else if(inderror == 1 && !ft_isreg(ft_makepath(".",(char*)lst1->content)) && !ft_islnk((ft_makepath(".",(char*)lst1->content))))
	{
		s1 = ft_memmove2((char*)(lst1->content));
		if (ind->ind1 == 0 && !ft_isreg(s1) && !ft_islnk(s1))
		{
			if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0 || ft_strcmp((char*)lst1->content,"--") == 0)))
			{
				ft_putstr_fd("ls: ", 2);
				ft_putstr_fd((char*)(lst1->content), 2);
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(strerror(errno),2);
				ft_putstr_fd("\n", 2);
			}
			ind->inderror = 1;
		}
	}
}

void	ft_p0error_p1_p1(t_lsto *lst1,t_ind *ind)
{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd((char*)(lst1->content), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno),2);
		ft_putstr_fd("\n", 2);
		ind->inderror = 1;
}
