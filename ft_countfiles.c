/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:29:57 by syusof            #+#    #+#             */
/*   Updated: 2016/02/24 08:13:02 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int		ft_countfiles(char *str)
{
	t_lst	*lstmp3;
	int		ret;

	ret = 0;
	lstmp3 = ft_getreplist(str);
	while(lstmp3 && ((t_name*)(lstmp3)->content)->name[0] == '.')
	{
		lstmp3 = lstmp3->next;
	}
	while(lstmp3)
	{
		lstmp3 = lstmp3->next;
		ret++;
	}
	printf("ret = %d\n",ret);
	return (ret);
}
