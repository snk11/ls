/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2015/11/05 11:21:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_name			*e;
	t_lst			*lstmp;
	t_lst			*lsta;

	lsta = NULL;
	lstmp = NULL;

	ac = 0;
	pdir1 = opendir(".");


	while ((pdirent1 = readdir(pdir1)))
	{
		if ((strncmp(pdirent1->d_name,".",1)) && (strncmp(pdirent1->d_name,"..",2)))
			printf("%s\n",pdirent1->d_name);
		
		if (!(e = (t_name*)malloc(sizeof(t_name))))
			return (0);
		e->name = pdirent1->d_name;
		lstmp = create_lst(e);

		lst_add(&lsta, &lstmp);


	}
	ft_sort(&lsta);
	closedir(pdir1);
	
	if(av[1])
//	if (strncmp(av[1], "-l",ft_strlen(av[1])))
	{
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
			//		printf("%s\n",ctime(&(sb.st_ctime)));

			printf("%d\n",(localtime(&(sb.st_ctime)))->tm_mon);
			printf("%d\n",(localtime(&(sb.st_ctime)))->tm_mday);
			printf("%d\n",(localtime(&(sb.st_ctime)))->tm_hour);
			printf("%d\n",(localtime(&(sb.st_ctime)))->tm_min);
			printf("%d\n",(localtime(&(sb.st_ctime)))->tm_year);

		}
	}


	return (0);
}
