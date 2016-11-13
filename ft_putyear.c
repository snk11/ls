/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putyear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:44:34 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 16:08:52 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putyear(char *s)
{
	int		cnt;

	cnt = 0;
	while (*s && cnt < 4)
	{
		while (*s && *s != ' ')
			s++;
		while (*s && *s == ' ')
			s++;
		cnt++;
	}
	while (*s && ft_isdigit(*s))
	{
		write(1, s, 1);
		s++;
	}
}

char		*ft_getyear(char *s)
{
	int		cnt;
	char	*sbegi;
	int		i;
	char	*str;

	cnt = 0;
	while (*s && cnt < 4)
	{
		while (*s && *s != ' ')
			s++;
		while(*s && *s == ' ')
			s++;
		cnt++;
	}
	sbegi = s;
	i = 0;
	while (*s && *s != ' ')
	{
//		write(1, s, 1);
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
	printf("i = %d\n",i);
	str[i] = 0;
	return (str);
}
