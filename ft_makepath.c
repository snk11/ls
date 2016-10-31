/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 00:45:57 by syusof            #+#    #+#             */
/*   Updated: 2016/10/31 22:20:18 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

char	*ft_makepath(char *str1,char *str2)
{
//	char*str;
	char*str3;
	int len;
//	int len1;
	int len2;
	int	i;
	int	j;

//	printf("str1 = %s\n",str1);
//	printf("str2 = %s\n",str2);
	len = ft_strlen(str1);
//	str = ft_strnew(len + 1 + 1);
//	i = 0;
//	while (i < len)
//	{
//		str[i] = str1[i];
//		i++;
//	}
//	str[i] = '/';
//	i++;
//	str[i] = 0;
//	str3 = ft_strjoin2(str,str2);
//	len1 = ft_strlen(str);
	/*
	len2 = ft_strlen(str2);
	str3 = ft_strnew(len + 1 + len2 + 1);
	i = 0;
	while(i < len)
	{
		str3[i] = str1[i];
		i++;
	}
	str3[i] = '/';
	i++;
	j = 0;
	while(j < len2)
	{
		str3[i] = str2[j];
		j++;
		i++;
	}
	str3[i] = 0;
//	free(str);
//	str = NULL;
//	if(ft_strcmp("./",str2) == 0)
		printf("str3 = %s\n",str3);
	*/
	str3 = ft_strnew(len + 1 + len2 + 1);
	i = 0;
	while(i < len)
	{
		str3[i] = str1[i];
		i++;
	}
	str3[i] = '/';
	i++;
	j = 0;
	while(j < len2)
	{
		str3[i] = str2[j];
		j++;
		i++;
	}

	str3[i] = 0;
//		free(str3);
//		str3 = NULL;
	return (str3);
}
