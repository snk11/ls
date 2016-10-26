/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:06:32 by syusof            #+#    #+#             */
/*   Updated: 2016/10/26 09:56:48 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_printname(char *s,t_lsto *lstcmd,t_ind *ind)
{
	t_lsto *lstmp;
	int	cnt;

	cnt = 0;
	lstmp = NULL;

	lstmp = lstcmd;
	while(lstmp)
	{
		lstmp = lstmp->next;
		cnt++;
	}
//	printf("char s = %s,index = %d,position = %d\n",s,ind->index1,ind->indposition);
	if (ft_checkhyphencase(lstcmd,ind) == 1)
	{
		if(ft_checkhyphencase_print(lstcmd,ind) == 1)
		{
		}
		else if(ind->indposition == 1 && cnt < 4)
		{
		}
		else if(ind->indposition == 1 && cnt >= 4)
		{
			ft_putstr(s);
			ft_putstr(":\n");
		}
		/*
		else if((ind->index1 == 1 && ind->indoption == 0) || ind->indexyet == 1)
		{
			ft_putstr(s);
			ft_putstr(":\n");
			ind->indexyet = 1;
		}
		else if(ind->index1 == 2 && ind->indregfile == 1)
		{
			ft_putstr(s);
			ft_putstr(":\n");
		}
		*/
		else if(ind->indposition >= 2)
		{
			ft_putstr(s);
			ft_putstr(":\n");
		}
	}
	else if(ft_checkhyphencase(lstcmd,ind) == 0)
	{
//		if(ind->indoption > 0 && cnt >= 3)
//		{
//			ft_putstr(s);
//			ft_putstr(":\n");
//		}
		if((ind->index1 == 1 && ind->indoption == 0) || ind->indexyet == 1)
		{
			ft_putstr(s);
			ft_putstr(":\n");
			ind->indexyet = 1;
		}
		else if(((ind->index1 == (2 + ind->indoption) && ft_checkhyphencase(lstcmd,ind) == 0) || ind->indexyet == 1) && ft_strcmp(s,"--") == 1)
		{
			ft_putstr(s);
			ft_putstr(":\n");
			ind->indexyet = 1;
		}
		else if(((ind->index1 == (2 + ind->indoption) && ft_checkhyphencase(lstcmd,ind) == 0) || ind->indexyet4 == 1))
		{
			ft_putstr(s);
			ft_putstr(":\n");
			ind->indexyet4 = 1;
		}
		else if(ind->index1 >= (2 + ind->indoption) )
		{
			ft_putstr(s);
			ft_putstr(":\n");
		}

	}
}

