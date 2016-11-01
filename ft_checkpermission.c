/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpermission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:24:16 by syusof            #+#    #+#             */
/*   Updated: 2016/11/01 18:45:50 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkpermission(char *s)
{
	struct stat		sb;
	int				r1;
	int				r2;
	int				r3;
	int				r4;
	int				r5;
	int				r6;
	int				r7;
	int				r8;
	int				r9;
	int				r10;
	int				r11;

	r1 = 0;
	r2 = 0;
	r3 = 0;
	r4 = 0;
	r5 = 0;
	r6 = 0;
	r7 = 0;
	r8 = 0;
	r9 = 0;
	r10 = 0;
	r11 = 0;
	lstat(s, &sb);
	ft_print_permission(s);




	if(S_ISLNK(sb.st_mode))
	{
	}
	else if(S_ISDIR(sb.st_mode))
	{
	}
	else if(S_ISSOCK(sb.st_mode))
	{
	}
	else if(S_ISBLK(sb.st_mode))
	{
	}
	else if(S_ISCHR(sb.st_mode))
	{
	}
	else if(S_ISFIFO(sb.st_mode))
	{
	}
	else if(S_ISREG(sb.st_mode))
		r1 = 1;
	if(sb.st_mode & S_IRUSR)
	{
		r2 = 1;
	}
	else
		r2 = 1;
	if(sb.st_mode & S_IWUSR)
	{
	}
	else
		r3 = 1;
	if((sb.st_mode & S_ISUID) && (sb.st_mode & S_IXUSR))
	{
	}
	else if(sb.st_mode & S_IXUSR)
	{
	}
	else if(sb.st_mode & S_ISUID)
	{
	}
	else
		r4 = 1;
	if(sb.st_mode & S_IRGRP)
	{
	}
	else
		r6 = 1;
	if(sb.st_mode & S_IWGRP)
	{
	}
	else
		r7 = 1;
	if((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
	{
	}
	else if(sb.st_mode & S_IXGRP)
	{
	}
	else if(sb.st_mode & S_ISGID)
	{
	}
	else
		r8 = 1;
	if(sb.st_mode & S_IROTH)
	{
	}
	else
		r9 = 1;
	if(sb.st_mode & S_IWOTH)
	{
	}
	else
		r10 = 1;
	if((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
	{
	}
	else if(sb.st_mode & S_IXOTH)
		r11 = 1;
	else if(sb.st_mode & S_ISVTX)
		r11 = 1;
	else
		r11 = 1;
	printf("r1 = %d\n",r1);
	printf("r1 = %d\n",r2);
	printf("r1 = %d\n",r3);
	printf("r1 = %d\n",r4);
	printf("r1 = %d\n",r5);
	printf("r1 = %d\n",r6);
	printf("r1 = %d\n",r7);
	printf("r1 = %d\n",r8);
	printf("r1 = %d\n",r9);
	printf("r1 = %d\n",r10);
	printf("r1 = %d\n",r11);
	if(r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1 && r6 == 1 && r7 == 1 && r8 == 1 && r9 == 1 && r10 == 1 && r11 == 1)
		return (1);
	return (0);

}
