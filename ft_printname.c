/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 00:06:32 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 11:12:56 by syusof           ###   ########.fr       */
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
	printf("char s = %s,index = %d,position = %d,ind->indhyphsolo = %d\n",s,ind->index1,ind->indposition,ind->indhyphsolo);
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
			ft_putstr(":1\n");
		}
	}
	else if(ft_checkhyphencase(lstcmd,ind) == 0)
	{
		if(ind->indoption > 0 && (cnt - ind->indoption) >= 2)
		{
			ft_putstr(s);
			ft_putstr(":2\n");
		}
		else if((ind->index1 == 1 && (ind->indoption == 0 || ind->indhyphsolo == 1)) || ind->indexyet == 1)
		{
			ft_putstr(s);
			ft_putstr(":3\n");
			ind->indexyet = 1;
		}
		else if(((ind->index1 == (2 + ind->indoption) && ft_checkhyphencase(lstcmd,ind) == 0) || ind->indexyet == 1) && ft_strcmp(s,"--") == 1)
		{
			ft_putstr(s);
			ft_putstr(":4\n");
			ind->indexyet = 1;
		}
		else if(((ind->index1 == (2 + ind->indoption) && ft_checkhyphencase(lstcmd,ind) == 0) || ind->indexyet4 == 1))
		{
			ft_putstr(s);
			ft_putstr(":5\n");
			ind->indexyet4 = 1;
		}
		else if(ind->index1 >= (2 + ind->indoption) )
		{
			ft_putstr(s);
			ft_putstr(":6\n");
		}
		/*
		else if((ind->index1 == 0 && ind->indhyphsolo == 1) || ind->indexyet5 == 1)
		{
			ft_putstr(s);
			ft_putstr(":7\n");
			ind->indexyet5 = 1;
		}
		*/

	}
}

