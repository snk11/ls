/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 12:07:58 by syusof            #+#    #+#             */
/*   Updated: 2016/05/15 12:11:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(t_lst *lst1)
{
	struct stat		sb;

	stat(((t_rep*)(lst1)->content)->name, &sb);
	if(S_ISDIR(sb.st_mode))
		return (1);
	return (0);
}