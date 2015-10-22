/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2015/10/22 22:52:15 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;

	ac = 0;
	pdir1 = opendir(av[1]);


	stat(av[1], &sb);
	{
		if(S_ISDIR(sb.st_mode))
			printf("d\n");
		if(sb.st_mode & S_IRUSR)
		{
			printf("r\n");
		}
		printf("%d\n",sb.st_nlink);
	}

	/*
	while ((pdirent1 = readdir(pdir1)))
	{
		printf("%s\n",pdirent1->d_name);
	}
	closedir(pdir1);
	return (0);
*/

}
