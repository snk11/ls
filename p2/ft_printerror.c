/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 02:37:03 by syusof            #+#    #+#             */
/*   Updated: 2016/06/13 20:40:20 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_printerror(char **av, t_ind *ind)
{
	int	i;
	t_lsto		*lst;
	t_lsto		*lst1;
	t_lsto		*lst2;
	int			ind2;
	

	lst = NULL;
	lst1 = NULL;
	lst2 = NULL;
	i = 1;
	while(av[i] && ind->indillegal != 0)
	{
		if (av[i][0] == '-' && ind->ind2 >= 0)
			ind->ind2 = 1;
		else
			ind->ind2 = -1;
		if (ind->ind2 == -1 || (ft_strcmp(av[i], "-1") != 0 && ft_strcmp(av[i], "--") != 0 && ft_strcmp(av[i], "-1R") != 0 && ft_strcmp(av[i],"-1a") != 0 && ft_strcmp(av[i],"-1r") != 0 && ft_strcmp(av[i],"-1t") != 0))
		{
//			if (!opendir(av[i]) && ft_isdir(av[i]))
//			{
//				ft_putstr_fd("ls: ", 2);
//				perror(av[i]);
//			}
			if (!ft_isdir(av[i]) && ft_isreg(av[i]))
//			if (!ft_isdir(av[i]))
			{
				lst = ft_create_lsto_char(av[i]);
				lst1 = lst_addo_down_char(lst1,lst);
//				ft_putstr(av[i]);
//				ft_putstr("\n");
			}
			else if (!opendir(av[i]) && !ft_isdir(av[i]))
//			else if (!ft_isdir(av[i]))
			{
				lst = ft_create_lsto_char(av[i]);
				lst2 = lst_addo_down_char(lst2,lst);
//				ft_putstr(av[i]);
//				ft_putstr("\n");

			}
		}
		i++;
	}
	lst1 = ft_lst_sort(lst1,croissant_char);
	lst2 = ft_lst_sort(lst2,croissant_char);
//	if (ind->indt == 1)
//	{
//		lst1 = ft_lst_sort(lst1,decreasing_time_char);
//		lst2 = ft_lst_sort(lst2,decreasing_time_char);
//	}
//	else if (ind->indone == 1)
//	{
//		lst1 = ft_lst_sort(lst1,croissant_char);
//		lst2 = ft_lst_sort(lst2,croissant_char);
//	}
	while (lst2)
	{
		opendir(lst2->content);
		ft_putstr_fd("ls: ", 2);
		perror(lst2->content);
//		ft_putstr("\n");
		lst2 = lst2->next;
	}
	while (lst1)
	{
		ft_putstr(lst1->content);
		ft_putstr("\n");
		lst1 = lst1->next;
	}
}
