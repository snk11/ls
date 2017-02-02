/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isreg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 05:08:20 by syusof            #+#    #+#             */
/*   Updated: 2017/02/02 13:15:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isreg(char *s)
{
	struct stat		sb;

	if (lstat(s, &sb) == 0)
	{
		if (!S_ISDIR(sb.st_mode))
			return (1);
	}
	return (0);
}
