/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2015/10/15 21:13:12 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;

	ac = 0;
	pdir1 = opendir(av[1]);

	while ((pdirent1 = readdir(pdir1)))
	{
		printf("%s\n",pdirent1->d_name);
	}
	closedir(pdir1);
	return (0);
}
