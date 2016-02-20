/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2016/02/20 12:41:21 by syusof           ###   ########.fr       */
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

/*
typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;
*/

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*next;
}						t_lst;


typedef struct			s_numb
{
	int					val;
}						t_numb;

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
void		push_swap(t_lst **lsta);
void		lst_add_del(t_lst **toplist, t_lst **t_lst1);
t_lst		*create_lst(void *content);
void	push(t_lst **lstb, t_lst **lsta);
void	reverse(t_lst **lsta);
void	reverse(t_lst **lsta);
void	rotate(t_lst **lsta);
void		ft_sort(t_lst **lsta);
void	swap(t_lst **lsta);

t_lst *ft_getreplist(char *rep);
void	ft_printlist(t_lst *lstmp);
int		ft_countlevel(t_lst *lstmp);
//void		lst_add1(t_lst **toplist, t_lst **t_lst1);
//t_lst		*create_lst1(void *content);
//void	swap(t_lst **lsta);
//void		ft_sort(t_lst **lsta);

# endif
