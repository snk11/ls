/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:42:54 by syusof            #+#    #+#             */
/*   Updated: 2016/11/15 10:49:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkdir(char *s1)
{
	if (ft_islnk(s1))
	{
		if (ft_isdir(ft_getlinkpath(s1)))
			return (1);
	}
	else
	{
		if (ft_isdir(s1))
			return (1);
	}
	return (0);
}
