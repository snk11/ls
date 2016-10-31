/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:03:20 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 16:04:13 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlst(t_lsto *lstmp)
{

	while(lstmp)
	{
		printf("lstmp =%s\n",(char*)lstmp->content);
			lstmp = lstmp->next;
	}
}
