/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0regfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:14:46 by syusof            #+#    #+#             */
/*   Updated: 2016/10/18 19:55:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


void	ft_p0regfile(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	int	inderror;
	char	*s1;

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
//		if(lst1)
//			printf("lst1 = %s\n",((char*)(lst1->content)));
//		printf("inderror = %d\n",inderror);
		ind->index1 = ft_getindex(lst1,lstcmd);
				printf("char = %s,index1 = %d\n",(char*)lst1->content,ind->index1);
		if(ft_strcmp((char*)lst1->content,"--") == 0 && ft_getindex(lst1,lstcmd) == 2 && ind->indone == 1)
		{
		}
		else if(ft_strcmp((char*)lst1->content,"--") == 0 && ft_getindex(lst1,lstcmd) == 1 && ind->indone == 0)
		{
		}
		else if(inderror == 1 && ind->indl == 1 && ft_isreg((char*)(lst1->content)))
		{
			ft_printlregfile((char*)(lst1->content));
			ind->indregfile = 1;
		}
		else if(inderror == 1 && ft_isreg(s1))
		{
			ft_putstr((char*)(lst1->content));
			ft_putstr("\n");
			ind->indregfile = 1;
		}
		lst1 = lst1->next;
	}

}
