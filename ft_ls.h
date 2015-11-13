/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2015/11/13 03:39:40 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H



# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "push_swap/push_swap.h"

/*
typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;
*/
typedef struct		s_name
{
	char			*name;
}					t_name;



typedef struct		s_stat
{
	char			*id;
	struct stat		stat1;
}					t_stat;


void		lst_add(t_lst **toplist, t_lst **t_lst1);
t_lst		*create_lst(void *content);
void	swap(t_lst **lsta);
void		ft_sort(t_lst **lsta);

# endif
