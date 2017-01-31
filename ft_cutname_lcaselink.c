/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutname_lcaselink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:09:36 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 23:50:42 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_cutname_lcaselink(char *s1)
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
		if (s2[i + 1])
		{
			i++;
			s = (char*)malloc(sizeof(s1) * ft_strlen(s1) + 1);
			j = 0;
			while (s1[i])
			{
				s[j] = s1[i];
				j++;
				i++;
			}
			s[j] = 0;
		}
	}
	else if (i == 0)
	{
		s = (char*)malloc(sizeof(s1) * ft_strlen(s1) + 1);
		i = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
		s[i] = 0;
	}
	return (s);
}
