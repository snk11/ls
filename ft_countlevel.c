/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlevel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:11:58 by syusof            #+#    #+#             */
/*   Updated: 2016/02/20 12:45:24 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int		ft_countlevel(t_lst *lstmp)
{
	int		ret;
	int		ret2;
	struct stat		sb;
	t_lst			*lstmp2;

	lstmp2 = NULL;
	ret = 0;
	while(lstmp)
	{
		stat(((t_name*)(lstmp2)->content)->name,&sb);
		if(S_ISDIR(sb.st_mode))
		{
			lstmp2 = ft_getreplist(((t_name*)(lstmp2)->content)->name);
			ret2 = ft_countlevel(lstmp2);
			if (ret < ret2)
				ret = ret2;
		}
		lstmp = lstmp->next;
	}
	ret++;
	return (ret);
}
