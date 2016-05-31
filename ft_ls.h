/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2016/05/31 16:05:58 by syusof           ###   ########.fr       */
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
#include <errno.h>
#include <string.h>

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
	struct s_lst		*nextl;
	struct s_lst		*nextr;
}						t_lst;

typedef struct			s_lsto
{
	void				*content;
	struct s_lsto		*next;
}						t_lsto;

typedef struct			s_rep
{
	char			*name;
	char			*path;
	int					val;
}						t_rep;

typedef struct			s_ind
{
	int					indminus1;
	int					indfirst;
}						t_ind;

typedef struct			s_numb
{
	int					val;
}						t_numb;

/*
typedef struct		s_name
{
	char			*name;
}					t_name;
*/
typedef struct		s_head
{
	t_lst			*lst;
}					t_head;

typedef struct		s_stat
{
	char			*id;
	struct stat		stat1;
}					t_stat;

t_lst		*lst_add(t_lst *toplist, t_lst *t_lst1);
void		lst_addo(t_lsto **toplist, t_lst *t_lst1);
t_lsto		*lst_addo_down(t_lsto *toplist, t_lsto *lst1);
void		lst_add_del(t_lst **toplist, t_lst **t_lst1);
t_lst		*ft_create_lst(void *content);
t_lsto		*ft_create_lsto(void *content);
t_lst *ft_getreplist(char *rep);
t_lst *ft_getreplist4(char *rep);
void	ft_printlist(t_lst *lstmp);
t_lsto	*ft_printlist2(t_lst *lstmp);
t_lsto	*ft_printlist3(t_lst *lstmp);
void	ft_printlist4(t_lst *lstmp);
void	ft_printlist5(t_lst *lstmp);
int		ft_countlevel(t_lst *lstmp);
char	*ft_makepath(char *str1,char *str2);
void	ft_push1stback(t_lst **lstmp);
int		ft_countfiles(char *str);
//void ft_addreplist(t_lst **lst1,t_lst *lst2,char *str);
void ft_addreplist(t_lst **lst1,t_lst *lst2,t_lst **lstname,t_lst **lstval);
void	ft_trailrep(t_lst **lst,char *str);
//t_lst		*create_lst1(void *content);
//void	swap(t_lst **lsta);
//void		ft_sort(t_lst **lsta);
int croissant(t_lsto *lsta);
int croissant_pathname(t_lsto *lsti);
t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*));
int		ft_isdir(char *s);
t_lsto		*ft_lst_sort1(t_lsto *lst);
t_lsto		*ft_lst_sort2(t_lsto *lst);
t_lsto	*ft_getreplisto4(t_lst *lstmp);
void	ft_init(t_ind ind);
t_lsto		*ft_lst_sort3(t_lsto *lst);
int decreasing(t_lsto *lsta);

# endif
