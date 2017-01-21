/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:47:43 by syusof            #+#    #+#             */
/*   Updated: 2017/01/21 03:04:23 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putwidth(char *s, int p)
{
	int		r;
	int		len;

	len = ft_strlen(s);
	r = p - len;
	while (r > 0)
	{
		ft_putstr(" ");
		r--;
	}
	ft_putstr(s);
}

void	ft_putwidth2(char *s, int p)
{
	int		r;
	int		len;

	len = ft_strlen(s);
	r = p - len;
	while (r > 0)
	{
		ft_putstr("0");
		r--;
	}
	ft_putstr(s);
}

void	ft_putwidth3(char *s, int p)
{
	int		r;
	int		len;

	len = ft_strlen(s);
	r = p - len;
	ft_putstr(s);
	while (r > 0)
	{
		ft_putstr(" ");
		r--;
	}
}
