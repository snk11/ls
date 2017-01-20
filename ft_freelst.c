/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:58:32 by syusof            #+#    #+#             */
/*   Updated: 2017/01/20 23:24:05 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_freelst(t_lsto **lstmp)
{
	if ((*lstmp))
	{
		if ((*lstmp)->content)
		{
			free((*lstmp)->content);
			(*lstmp)->content = NULL;
		}
		free((*lstmp));
		(*lstmp) = NULL;
	}
}

void		ft_freelst2(t_lsto **lstmp)
{
	if (*lstmp)
	{
		if ((*lstmp)->content)
		{
			if (((t_rep*)((*lstmp)->content))->name)
			{
				free(((t_rep*)((*lstmp)->content))->name);
				(((t_rep*)((*lstmp)->content))->name) = NULL;
			}
			if (((t_rep*)((*lstmp)->content))->path)
			{
				free(((t_rep*)((*lstmp)->content))->path);
				(((t_rep*)((*lstmp)->content))->path) = NULL;
			}
			free((*lstmp)->content);
			(*lstmp)->content = NULL;
		}
		free((*lstmp));
		(*lstmp) = NULL;
	}
}

void	ft_free2(t_rep **e)
{
	if (*e)
	{
		if ((*e)->path)
		{
			free((*e)->path);
			(*e)->path = NULL;
		}
		if ((*e)->name)
		{
			free((*e)->name);
			(*e)->name = NULL;
		}
		free(*e);
		*e = NULL;
	}
}
