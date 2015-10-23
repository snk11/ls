/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2015/10/23 17:23:47 by syusof           ###   ########.fr       */
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

		printf("%s\n",getpwuid(sb.st_uid)->pw_name);
		printf("%s\n",getgrgid(sb.st_gid)->gr_name);
		printf("%lld\n",sb.st_size);
		printf("%lld\n",sb.st_size);
		printf("%s\n",ctime(&(sb.st_ctime)));
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
