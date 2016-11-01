/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkokfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:00:51 by syusof            #+#    #+#             */
/*   Updated: 2016/11/01 21:31:35 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkokfile(char *s)
{
	struct stat		sb;

	if(lstat(s, &sb) == 0)
	{
		if(S_ISLNK(sb.st_mode))
			return (1);
		else if(S_ISDIR(sb.st_mode))
			return (1);
		else if(S_ISSOCK(sb.st_mode))
			return (1);
		else if(S_ISBLK(sb.st_mode))
			return (1);
		else if(S_ISCHR(sb.st_mode))
			return (1);
		else if(S_ISFIFO(sb.st_mode))
			return (1);
		else if(S_ISREG(sb.st_mode))
			return (1);
	}
	return (0);
}
