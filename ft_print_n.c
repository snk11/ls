/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:18:14 by syusof            #+#    #+#             */
/*   Updated: 2016/10/20 01:29:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_print_n(char *s,t_lsto *lstcmd,t_ind *ind)
{
	if(ft_checkhyphencase(lstcmd,ind) == 1)
	{
		if((ind->index1 <= 2 && ft_checkhyphencase(lstcmd,ind) == 1) && ind->indexyet2 < 2 && ft_strcmp(s,"--") == 0)
			ind->indexyet2++;
		else if((ind->index1 == 2 && ft_checkhyphencase(lstcmd,ind) == 1) && ind->indexyet3 == 0)
			ind->indexyet3 = 1;
		else if (ind->indregfile == 1 && ind->inderror == 1)
			ft_putstr("\n");
		else if (ind->indfirst > 1 && ind->indregfile == 0 && ind->inderror == 0)
			ft_putstr("\n");
		/*
		else if (ind->indfirst > 1 && (ind->indregfile == 0 || ind->inderror == 0))
		{
			ind->inderror = 0;
			ind->indregfile = 0;
		}
		*/
	}
	else if (ft_checkhyphencase(lstcmd,ind) == 0)
	{
//		printf("first = %d,regfile = %d, inderror =%d\n",ind->indfirst,ind->indregfile,ind->inderror);
		if (ind->indregfile == 1 && ind->inderror == 0)
			ft_putstr("\n");
		else if (ind->indregfile == 1 && ind->inderror == 1)
			ft_putstr("\n");
		else if (ind->indfirst > 1 && ind->indregfile == 0 && ind->inderror == 0)
			ft_putstr("\n");
		/*
		else if (ind->indfirst > 1 && (ind->indregfile == 0 || ind->inderror == 0))
		{
			ind->inderror = 0;
			ind->indregfile = 0;
		}
		*/

	}

}
