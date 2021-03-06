/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 23:56:10 by syusof            #+#    #+#             */
/*   Updated: 2017/03/09 01:50:29 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkdev(char *s)
{
	char	*s1;
	int		i;

	s1 = ft_getname_without_slash(s);
	i = 0;
	if (s1)
	{
		while (s1[i])
			i++;
		while (s1[i] != '/' && i > 0)
			i--;
		if (ft_strcmp("fd", &(s1[i])) == 0)
			return (1);
	}
	return (0);
}
