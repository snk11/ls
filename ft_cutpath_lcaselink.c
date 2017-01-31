/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutpath_lcaselink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:42:55 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 20:37:08 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_cutpath_lcaselink(char *s1)
{
	char	*s;
	char	*s2;
	int		i;
	int		j;

	s = NULL;
	s2 = s1;
	if (s2)
	{
		i = 0;
		while (s2[i])
			i++;
		while (s2[i] != '/' && i != 0)
			i--;
	}
	if (s2[i] == '/')
	{
		if (i != 0)
		{
			s = (char*)malloc(sizeof(s1) * i + 1);
			j = 0;
			while (s1[j] && j < i)
			{
				s[j] = s1[j];
				j++;
			}
			s[j] = 0;
		}
		else if (i == 0)
			s = "";
	}
	else if (i == 0)
		s = ".";
	return (s);
}
