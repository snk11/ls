/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2016/10/19 13:46:32 by syusof           ###   ########.fr       */
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
//	int					nbelem;
	int					indexyet;
	int					indhyphen;
	int					indregfile;
	int					inderror;
	int					index1;
	int					indfirst;
	int					indtotal;
	int					indone;
	int					indr;
	int					indt;
	int					inda;
	int					indl;
	int					indreverse;
	char				indillegal;
	int					indoption;
	int					ind1;
	int					ind2;
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

void	ft_p1(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd);
t_lst		*lst_add(t_lst *toplist, t_lst *t_lst1);
void		lst_addo(t_lsto **toplist, t_lsto *t_lst1);
t_lsto		*lst_addo_down(t_lsto *toplist, t_lsto *lst1);
t_lsto		*lst_addo_down_char(t_lsto *toplist, t_lsto *lst1);
void		lst_add_del(t_lst **toplist, t_lst **t_lst1);
t_lst		*ft_create_lst(void *content);
t_lsto		*ft_create_lsto(void *content);
t_lsto		*ft_create_lsto_char(char *content);
t_lsto *ft_getreplist(char *rep);
t_lsto *ft_getreplist4(char *rep);
t_lsto	*ft_getreplisto4(t_lsto *lstmp);
void	ft_printlist(t_lsto *lstmp);
t_lsto	*ft_printlist2(t_lsto *lstmp);
t_lsto	*ft_printlist3(t_lsto *lstmp);
void	ft_printlist4(t_lsto *lstmp);
void	ft_printlist5(t_lsto *lstmp);
void	ft_printlist6(t_lsto *lstmp);
void	ft_printlist7(t_lsto *lstmp);
t_lsto	*ft_printlist8(t_lsto *lstmp);
void	ft_printlist9(t_lsto *lstmp);
t_lsto	*ft_printlist10(t_lsto *lstmp);
t_lsto	*ft_printlist11(t_lsto *lstmp);
t_lsto	*ft_printlist12(t_lsto *lstmp);
void	ft_printlist13(t_lsto *lstmp);
void	ft_printlist14(t_lsto *lstmp);
void	ft_printlist15(t_lsto *lstmp);
t_lsto	*ft_printlist16(t_lsto *lstmp);
t_lsto	*ft_printlist17(t_lsto *lstmp);
t_lsto	*ft_printlist18(t_lsto *lstmp);
t_lsto	*ft_printlist19(t_lsto *lstmp);
t_lsto	*ft_printlist20(t_lsto *lstmp);
void	ft_printlist21(t_lsto *lstmp);
t_lsto	*ft_printlist22(t_lsto *lstmp);
t_lsto	*ft_printlist23(t_lsto *lstmp);
void	ft_printlist24(t_lsto *lstmp);
t_lsto	*ft_printlist25(t_lsto *lstmp);
t_lsto	*ft_printlist26(t_lsto *lstmp);
t_lsto	*ft_printlist27(t_lsto *lstmp);
t_lsto	*ft_printlist28(t_lsto *lstmp);
t_lsto	*ft_printlist29(t_lsto *lstmp);
t_lsto	*ft_printlist30(t_lsto *lstmp);
t_lsto	*ft_printlist31(t_lsto *lstmp);
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
int croissant_char(t_lsto *lsta);
int croissant_pathname(t_lsto *lsti);
t_lsto		*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*));
int		ft_isdir(char *s);
int		ft_isreg(char *s);
//t_lsto		*ft_lst_sort1(t_lsto *lst);
//t_lsto		*ft_lst_sort2(t_lsto *lst);
//t_lsto		*ft_lst_sort4(t_lsto *lst);
void	ft_init(t_ind *ind);
//t_lsto		*ft_lst_sort3(t_lsto *lst);
int decreasing(t_lsto *lsta);
int decreasing_char(t_lsto *lsta);
int croissant_time(t_lsto *lsta);
int croissant_time_char(t_lsto *lsta);
int decreasing_time(t_lsto *lsta);
int decreasing_time_char(t_lsto *lsta);
void ft_t(char *s, t_ind *ind);
void ft_r(char *s, t_ind *ind);
void ft_printerror(char **av, t_ind *ind);
void ft_scan_ind(char **av,t_ind *ind);
void	ft_scan_option(char **av,t_ind *ind);
void	ft_print_permission(char *s);
void	ft_printlregfile(char *s);
void	ft_printldir(char *s,t_ind *ind);
void	ft_printlrdir(char *s,t_ind *ind);
void	ft_printltdir(char *s,t_ind *ind);
void	ft_printlreversedir(char *s,t_ind *ind);
int	ft_check_string(char *s);
void	ft_a(char *s, t_ind *ind);
void	ft_reverse(char *s, t_ind *ind);
void	ft_areverse(char *s, t_ind *ind);
void ft_at(char *s, t_ind *ind);
void ft_ar(char *s, t_ind *ind);
void ft_atreverse(char *s, t_ind *ind);
void ft_rt(char *s, t_ind *ind);
t_lsto		*lst_addo_between(t_lsto *toplist, t_lsto *lst1);
void ft_rreverse(char *s, t_ind *ind);
void ft_treverse(char *s, t_ind *ind);
void ft_art(char *s, t_ind *ind);
void	ft_printlardir(char *s,t_ind *ind);
void	ft_printladir(char *s,t_ind *ind);
void	ft_printlrtdir(char *s,t_ind *ind);
void	ft_printlrreversedir(char *s,t_ind *ind);
void	ft_printlatdir(char *s,t_ind *ind);
void	ft_printltreversedir(char *s,t_ind *ind);
void	ft_printlareversedir(char *s,t_ind *ind);
void ft_trreverse(char *s, t_ind *ind);
void ft_arreverse(char *s, t_ind *ind);
void	ft_printlatreversedir(char *s,t_ind *ind);
void	ft_printlartdir(char *s,t_ind *ind);
void	ft_printltrreversedir(char *s,t_ind *ind);
void	ft_printlarreversedir(char *s,t_ind *ind);
void ft_printlatrreversedir(char *s, t_ind *ind);
void ft_atrreverse(char *s, t_ind *ind);
t_lsto		*ft_getprimelist(char **av);
void	ft_putlongnbr(long n);
void	ft_putulongnbr(unsigned long n);
void	ft_p0regfile(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd);
void	ft_p0error(t_lsto *lst1,t_ind *ind,t_lsto *lstcmd);
int		ft_getindex(t_lsto *lst1,t_lsto *lstcmd);
int	ft_checkhyphen(t_lsto *lst1,t_lsto *lstcmd,t_ind *ind);
int		ft_checkhyphencase(t_lsto *lst1,t_ind *ind);

# endif
