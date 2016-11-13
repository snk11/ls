/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getyear_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:11:55 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 17:43:39 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getyear_str(char *s)
{
	int		cnt;
	char	*sbegi;
	int		i;
	char	*str;

	ft_getyear_str_p1(&s, &cnt);
	sbegi = s;
	i = 0;
	while (*s && *s != ' ')
	{
		s++;
		i++;
	}
	str = (char*)malloc(sizeof(char) * i + 1);
	s = sbegi;
	i = 0;
	while (*s && ft_isdigit(*s))
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = 0;
	return (str);
}

void		ft_getyear_str_p1(char **s, int *cnt)
{
	*cnt = 0;
	while (**s && (*cnt) < 4)
	{
		while (**s && **s != ' ')
			(*s)++;
		while (**s && **s == ' ')
			(*s)++;
		(*cnt)++;
	}
}
