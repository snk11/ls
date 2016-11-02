/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p0error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:31:27 by syusof            #+#    #+#             */
/*   Updated: 2016/11/02 13:49:10 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_p0error(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd)
{
	struct stat		sb;
	int		inderror;
	char	*s1;
	int		ind1;
	struct passwd	*uid;

	ind1 = 0;
	{
		ind->indexyet = 0;
		while(lst1 && ind->indfts == 0)
		{	
//			if(ft_checkslash((char*)(lst1->content)) == 1)
//			if(ft_checkokfile((char*)lst1->content))
//			{
//				if(lstat((char*)(lst1->content), &sb) == 0)
//				{
//					if((uid = getpwuid(sb.st_uid)) != NULL)
//						ind1 = 1;
//				}
//			}
//
//			if(ft_strcmp(getpwuid(sb.st_uid)->pw_name,"root") != 0)
			{
				if(ft_strcmp(((char*)lst1->content),"") == 0)
				{
					ind->indfts = 1;
					opendir((char*)(lst1->content));
					ft_putstr_fd("ls: fts_open: ", 2);
					ft_putstr_fd(strerror(errno),2);
					ft_putstr_fd("\n", 2);
					ind->inderror = 1;
				}
				else
				{
					inderror = 0;
					ind->ind1 = 0;
					{
						if (!opendir((char*)(lst1->content)))
						{
							inderror = 1;
						}
					}
//					printf("islnk = %d ,isreg = %d,inderror = %d,lst1 = %s\n",ft_islnk(ft_makepath("./",(char*)lst1->content)),ft_isreg(ft_makepath("./",(char*)lst1->content)),inderror,(char*)lst1->content);
					//if(ft_scan_option2((char*)lst1->content) && inderror == 1 && !ft_isreg((char*)lst1->content) && !ft_islnk((char*)lst1->content))
			
//					if(ind1 == 1 && ft_strcmp(uid->pw_name,"syusof") != 0)
					{
					}
					if(inderror == 1 && !ft_isreg(ft_makepath(".",(char*)lst1->content)) && !ft_islnk(ft_makepath(".",(char*)lst1->content)))
					{
						ft_putstr_fd("ls: ", 2);
						ft_putstr_fd((char*)(lst1->content), 2);
						ft_putstr_fd(": ", 2);
						ft_putstr_fd(strerror(errno),2);
						ft_putstr_fd("\n", 2);
						ind->inderror = 1;
					}
					else if(ft_checkhyphencase(lstcmd,ind) == 1 &&  ind->indoption > 0 && ind->indexyet == 0 && ft_strcmp((char*)lst1->content,"--") == 0)
					{
						ind->indexyet = 1;
					}
					else if(inderror == 1 && !ft_isreg(ft_makepath(".",(char*)lst1->content)) && !ft_islnk((ft_makepath(".",(char*)lst1->content))))
					{
						s1 = ft_memmove2((char*)(lst1->content));
						if (ind->ind1 == 0 && !ft_isreg(s1) && !ft_islnk(s1))
						{
							if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0 || ft_strcmp((char*)lst1->content,"--") == 0)))
								//				if ((!opendir((char*)(lst1->content)) && ind->indoption == 0))
								//				if(ft_strcmp((char*)(lst1->content),"-") == 0)
							{
								ft_putstr_fd("ls: ", 2);
								ft_putstr_fd((char*)(lst1->content), 2);
								ft_putstr_fd(": ", 2);
								ft_putstr_fd(strerror(errno),2);
								ft_putstr_fd("\n", 2);
								//					perror((char*)(lst1->content));
							}
							//				else if ((!opendir((char*)(lst1->content)) && (((char*)(lst1->content))[0] != '-' || ind->indoption == 0)))
							{
								//					ft_putstr_fd("ls: ", 2);
								//					ft_putstr_fd((char*)(lst1->content), 2);
								//					ft_putstr_fd(": ", 2);
								//					ft_putstr_fd(strerror(errno),2);
								//					ft_putstr_fd("\n", 2);
								//					perror((char*)(lst1->content));
							}
							ind->inderror = 1;
						}
					}
				}
			}
			lst1 = lst1->next;
		}
	}
}
