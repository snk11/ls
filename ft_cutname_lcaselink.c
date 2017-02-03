/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutname_lcaselink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:09:36 by syusof            #+#    #+#             */
/*   Updated: 2017/02/03 03:33:17 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_cutname_lcaselink(char *s1)
{
	char	*s;
	char	*s2;
	int		i;

	s = NULL;
	s2 = s1;
	ft_cutname_lcaselink_p1(&i, s2);
	if (s2[i] == '/')
		ft_cutname_lcaselink_p2(&s, s1, s2, i);
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

void	ft_cutname_lcaselink_p1(int *i, char *s2)
{
	if (s2)
	{
		*i = 0;
		while (s2[*i])
			(*i)++;
		while (s2[*i] != '/' && *i != 0)
			(*i)--;
	}
}

void	ft_cutname_lcaselink_p2(char **s, char *s1, char *s2, int i)
{
	int		j;
		if (s2[i + 1])
		{
			i++;
			*s = (char*)malloc(sizeof(s1) * ft_strlen(s1) + 1);
			j = 0;
			while (s1[i])
			{
				(*s)[j] = s1[i];
				j++;
				i++;
			}
			(*s)[j] = 0;
		}
}
