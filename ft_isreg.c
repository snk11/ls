/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isreg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 05:08:20 by syusof            #+#    #+#             */
/*   Updated: 2016/06/13 05:15:31 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isreg(char *s)
{
	struct stat		sb;

	stat(s, &sb);
	if(S_ISREG(sb.st_mode))
		return (1);
	return (0);
}