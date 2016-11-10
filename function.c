/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:43:19 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 17:08:36 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


t_lsto		*ft_create_lsto_char(char *content)
{
	t_lsto	*curlst;

	curlst = NULL;
	if (!(curlst = (t_lsto*)malloc(sizeof(t_lsto))))
		return (NULL);
	if (content == NULL)
	{
		curlst->content = NULL;
	}
	else
	{
		curlst->content = ft_memmove2(content);
	}
	curlst->next = NULL;
	return (curlst);
}
