/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:51:00 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 07:05:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_p2(char **av, t_lsto **lstcmd)
{
	int			i;
	t_lsto		*lstmp;

	lstmp = NULL;
	i = 1;
	while (av[i])
	{
		lstmp = ft_create_lsto_char(av[i]);
		*lstcmd = lst_addo_down_char(*lstcmd, lstmp);
		i++;
	}
}
