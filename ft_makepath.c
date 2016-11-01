/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 00:45:57 by syusof            #+#    #+#             */
/*   Updated: 2016/11/01 02:10:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

char	*ft_makepath(char *str1,char *str2)
{
	char	*str;
	char	*str3;
	int len;
	int	i;

	str3 = NULL;
	len = ft_strlen(str1);
	str = ft_strnew(len + 1 + 1);
	i = 0;
	while (i < len)
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '/';
	i++;
	str[i] = 0;
	str3 = ft_strjoin(str,str2);
	free(str);
	str = NULL;
	return (str3);
}
