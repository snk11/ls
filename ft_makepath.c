/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 00:45:57 by syusof            #+#    #+#             */
/*   Updated: 2016/02/25 08:44:33 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

char	*ft_makepath(char *str1,char *str2)
{
	char*str;
	int len;
	int	i;

	len = ft_strlen(str1);
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '/';
	ft_strncat(str,str2, ft_strlen(str2));
	return (str);
}
