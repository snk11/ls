/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlevel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:11:58 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 12:49:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
/*
int		ft_countlevel(t_lst *lstmp)
{
	int		ret;
	int		ret2;
	int		i;
	struct stat		sb;
	t_lst			*lstmp2;

	lstmp2 = NULL;
	ret = 0;
	ret2 = 0;
	while(lstmp)
	{
			while(lstmp && ((t_name*)(lstmp)->content)->name[0] == '.')
			{
//				if (lstmp2 ->next)
					lstmp = lstmp->next;
//				i++;
			}
		if (lstmp)
		{
			stat(((t_name*)(lstmp)->content)->name,&sb);
			ft_putstr(((t_name*)(lstmp)->content)->name);
			ft_putstr("\n");
		}
		if(S_ISDIR(sb.st_mode) && lstmp)
		{
			lstmp2 = ft_getreplist(((t_name*)(lstmp)->content)->name);
			i = 0;
			while(lstmp2 && ((t_name*)(lstmp2)->content)->name[0] == '.')
			{
//				if (lstmp2 ->next)
					lstmp2 = lstmp2->next;
//				i++;
			}
			if (lstmp2)
			{
				ft_putstr("lstmp2 = ");
				ft_putstr(((t_name*)(lstmp2)->content)->name);
				ft_putstr("\n");
				ret2 = ft_countlevel(lstmp2);
			if (ret < ret2)
				ret = ret2;
			}
		}
		lstmp = lstmp->next;
	}
	ret++;
	return (ret);
}
*/

