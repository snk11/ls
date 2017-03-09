/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getname_without_slash.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 06:13:13 by syusof            #+#    #+#             */
/*   Updated: 2017/03/09 01:41:47 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getname_without_slash(char *s)
{
	int		i;
	int		j;
	int		index;
	char	*str;

	str = NULL;
	ft_getname_without_slash_p1(&i, &index, &j, s);
	if (j > 0)
	{
		str = (char*)malloc(sizeof(char) * j + 1);
		i = 0;
		if (s[index] == '/')
			index++;
		while (s[index] && s[index] != '/')
		{
			str[i] = s[index];
			i++;
			index++;
		}
		str[i] = 0;
	}
	return (str);
}

void		ft_getname_without_slash_p1(int *i, int *index, int *j, char *s)
{
	*i = 0;
	*index = 0;
	while (s[*i])
	{
		if (s[*i] == '/' && s[*i + 1] && s[*i + 1] != '/')
			*index = *i;
		(*i)++;
	}
	*i = *index;
	if (s[*i] == '/')
		(*i)++;
	*j = 0;
	while (s[*i] && s[*i] != '/')
	{
		(*i)++;
		(*j)++;
	}
}
