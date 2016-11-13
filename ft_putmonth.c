/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmonth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:42:33 by syusof            #+#    #+#             */
/*   Updated: 2016/11/13 17:44:26 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putmonth(char *s)
{
	while (*s && *s != ' ')
		s++;
	while (*s && *s == ' ')
		s++;
	while (*s && ft_isalpha(*s))
	{
		write(1, s, 1);
		s++;
	}
}
