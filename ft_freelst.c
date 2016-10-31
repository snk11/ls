/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:58:32 by syusof            #+#    #+#             */
/*   Updated: 2016/10/31 20:17:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_freelst(t_lsto **lstmp)
{
	free(((t_rep*)((*lstmp)->content))->name);
	(((t_rep*)((*lstmp)->content))->name) = NULL;
	free(((t_rep*)((*lstmp)->content))->path);
	(((t_rep*)((*lstmp)->content))->path) = NULL;
	if((*lstmp)->content)
	{
		free((*lstmp)->content);
		(*lstmp)->content = NULL;
	}
	if((*lstmp))
	{
		free((*lstmp));
		(*lstmp) = NULL;
	}
}

void		ft_freelst2(t_lsto **lstmp)
{
//	free(((t_rep*)((*lstmp)->content))->name);
//	(((t_rep*)((*lstmp)->content))->name) = NULL;
//	free(((t_rep*)((*lstmp)->content))->path);
//	(((t_rep*)((*lstmp)->content))->path) = NULL;
	if((*lstmp)->content)
	{
		free((*lstmp)->content);
		(*lstmp)->content = NULL;
	}
}
