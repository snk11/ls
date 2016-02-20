/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/02/20 14:44:07 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
//# include "push_swap/push_swap.h"


int main(int ac,char **av)
{
	struct dirent	*pdirent1;
	DIR				*pdir1;
	struct stat		sb;
	t_name			*e;
	t_name			*e2;
	t_lst			*lstmp;
	t_lst			*lstmp2;
	t_lst			*lsta;
	t_lst			*lstb;
	int i;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;



	lsta = ft_getreplist(".");
	
	lstmp = lsta;
	if(av[1])
//	if (strncmp(av[1], "-l",ft_strlen(av[1])))
	{
		if (strcmp(av[1], "-1") == 0)
		{
			if(ac > 2)
			{
				i = 2;
				while (av[i])
				{
					if (!(e2 = (t_name*)malloc(sizeof(t_name))))
						return (0);
					e2->name = ft_strsub(av[i],0,ft_strlen(av[i]));
					lstmp2 = create_lst(e2);
					lst_add(&lstb, &lstmp2);
					i++;
				}
				push_swap(&lstb);
				lstmp2 = lstb;
				while (lstmp)
				{
					while (lstmp2)
					{
						if ( (((t_name*)(lstmp)->content)->name)[0] != '.' && strcmp((((t_name*)((lstmp))->content)->name),((t_name*)(lstmp2)->content)->name) == 0)
						{
							ft_putstr(((t_name*)(lstmp2)->content)->name);
							ft_putstr(":\n");
							if (lstmp2->next)
								ft_putstr("\n");
						}
						lstmp2 = lstmp2->next;
					}
					lstmp2 = lstb;
					lstmp = lstmp->next;
				}
			}
			else
			{
				ft_printlist(lstmp);
			}
		}
		else if (strcmp(av[1], "-1R") == 0)
		{
			int level = 0;

			level = ft_countlevel(lstmp);
			printf("level = %d\n",level);
//			while(lstmp)
//			{
//				stat(lstmp, &sb);

//			}
//			ft_printlist(lstmp);
//			while(lstmp)
//			{
//				stat(lstmp, &sb);
//				if(S_ISDIR(sb.st_mode))
//					lstmp2 = ft_getreplist(lstmp);
//				lstmp = lstmp->next;
//			}
		}
/*
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
		*/
	}


	return (0);
}
