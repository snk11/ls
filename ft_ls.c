/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/02/24 08:40:55 by syusof           ###   ########.fr       */
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
	t_numb			*e3;
	t_name			*e4;
	t_lst			*lstmp;
	t_lst			*lstmp2;
	t_lst			*lstmp3;
	t_lst			*lsta;
	t_lst			*lstb;
	t_lst			*lstval;
	t_lst			*lstname;
	int i;
	int ind0;
	int ind1;
	int indp;
	int nbfiles;
	char	*str1 = ".";
	char	*strbuf;
	char	*strbuf1;
	char	*namerep;

	lsta = NULL;
	lstb = NULL;
	lstmp = NULL;
	lstmp2 = NULL;
	lstmp3 = NULL;
	strbuf = str1;
	strbuf1 = NULL;
	lstname = NULL;
	namerep = NULL;

	ind0 = 0;
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
//			level = ft_countlevel(lstmp);
//			printf("level = %d\n",level);
//			while(lstmp)
//			{
//				stat(lstmp, &sb);

//			}
//			ft_printlist(lstmp);
			ind0 = 0;
			ind1 = 0;
			indp = 0;
			nbfiles = 0;
			i = 0;
						lstmp3 = lstmp;
						while(lstmp3 && ((t_name*)(lstmp3)->content)->name[0] == '.')
							lstmp3 = lstmp3->next;
						if (!(e3 = (t_numb*)malloc(sizeof(t_numb))))
							return (0);
						e3->val = ft_countfiles(".");
						lstmp2 = create_lst(e3);
						lst_add1(&lstval, lstmp2);
						if (!(e4 = (t_name*)malloc(sizeof(t_name))))
							return (0);
						e4->name = ".";
						lstmp2 = create_lst(e4);
						lst_add1(&lstname, lstmp2);
						namerep = ((t_name*)(lstname)->content)->name;
						nbfiles = ((t_numb*)(lstval->content))->val;
						ft_putstr(((t_name*)(lstmp3)->content)->name);
						ft_putstr("\n");
						ft_putstr("nbfiles =");
						ft_putnbr(nbfiles);
						ft_putstr("\n");
			while(ind1 == 0)
			{
				printf("i = %d\n",i);
				i++;
						ft_putstr("nbfiles =");
						ft_putnbr(nbfiles);
						ft_putstr("\n");
//				if (indp == 0)
				{
					/*
					if (ind0 == 0)
					{
						lstmp3 = lstmp;
						while(lstmp3 && ((t_name*)(lstmp3)->content)->name[0] == '.')
							lstmp3 = lstmp3->next;
						if (!(e3 = (t_numb*)malloc(sizeof(t_numb))))
							return (0);
						e3->val = ft_countfiles(".");
						lstmp2 = create_lst(e3);
						lst_add1(&lstval, &lstmp2);
						if (!(e4 = (t_name*)malloc(sizeof(t_name))))
							return (0);
						e4->name = ".";
						lstmp2 = create_lst(e4);
						lst_add1(&lstname, &lstmp2);
						namerep = ((t_name*)(lstname)->content)->name;
						nbfiles = ((t_numb*)(lstval->content))->val;
						ft_putstr(((t_name*)(lstmp3)->content)->name);
						ft_putstr("\n");
						ft_putstr("nbfiles =");
						ft_putnbr(nbfiles);
						ft_putstr("\n");
						stat(((t_name*)(lstmp3)->content)->name,&sb);
						ind0 = 1;
					}
					*/
//					else
					{
						if (nbfiles == 0)
						{
							lstname = lstname->next;
							namerep = ((t_name*)(lstname)->content)->name;
							lstval = lstval->next;
							nbfiles = ((t_numb*)(lstval->content))->val;
							ft_addreplist(&lstmp3,namerep);
						}
						while(lstmp3 && ((t_name*)(lstmp3)->content)->name[0] == '.')
							lstmp3 = lstmp3->next;
						if (!(e3 = (t_numb*)malloc(sizeof(t_numb))))
							return (0);
						ft_putstr(((t_name*)(lstmp3)->content)->name);
						ft_putstr("\n");
						ft_putstr("rep prime =");
						ft_putstr(namerep);
						ft_putstr("\n");
						ft_putstr("nbfiles =");
						ft_putnbr(nbfiles);
						ft_putstr("\n");
						stat(((t_name*)(lstmp3)->content)->name,&sb);
						strbuf = ((t_name*)(lstmp3)->content)->name;
					}
					if(S_ISDIR(sb.st_mode))
					{
						printf("in\n");
							strbuf1 = ft_makepath(namerep,((t_name*)(lstmp3)->content)->name);
//						while (strbuf)
						lstmp3 = lstmp3->next;
						{
							if (!(e4 = (t_name*)malloc(sizeof(t_name))))
								return (0);
							e4->name = ft_strsub(strbuf1,0,ft_strlen(strbuf1));
							lstmp2 = create_lst(e4);
							lst_add1(&lstmp3, lstmp2);
							ft_push1stback(&lstmp3);
						if (!(e3 = (t_numb*)malloc(sizeof(t_numb))))
							return (0);
						e3->val = ft_countfiles(strbuf1);
						lstmp2 = create_lst(e3);
						lst_add1(&lstval, lstmp2);
						ft_push1stback(&lstval);
						if (!(e4 = (t_name*)malloc(sizeof(t_name))))
							return (0);
						e4->name = strbuf1;
						lstmp2 = create_lst(e4);
						lst_add1(&lstname, lstmp2);
						ft_push1stback(&lstname);
//						ft_putstr(((t_name*)(lstmp3)->content)->name);
//						ft_putstr("\n");
						}
						nbfiles--;
					}
					else
					{
						lstmp3 = lstmp3->next;
						nbfiles--;
					}
					if (!lstmp3)
					{
//						indp = 1;
						ind1 = 1;
					}
				}
				/*
				else if (lstb)
				{
					lstmp3 = ft_getreplist(((t_name*)(lstb)->content)->name);
					while(lstmp3 && ((t_name*)(lstmp3)->content)->name[0] == '.')
						lstmp3 = lstmp3->next;
					ft_putstr(((t_name*)(lstmp3)->content)->name);
					ft_putstr("\n");
					stat(((t_name*)(lstmp3)->content)->name,&sb);
					strbuf = ((t_name*)(lstmp3)->content)->name;
					if(S_ISDIR(sb.st_mode))
					{
						strbuf1 = ft_makepath(strbuf,((t_name*)(lstmp3)->content)->name);
//						while (strbuf)
						{
							if (!(e2 = (t_name*)malloc(sizeof(t_name))))
								return (0);
							e2->name = ft_strsub(strbuf1,0,ft_strlen(strbuf1));
							lstmp2 = create_lst(e2);
							lst_add(&lstb, &lstmp2);
							push_swap(&lstb);
						}
					}
					lstb = lstb->next;
					if (!lstb)
					{
						indp = 0;
					}
				}
				*/
				if (!lstmp)
					ind1 = 1;
			}
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
