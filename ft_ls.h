/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2017/01/31 19:57:49 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
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
# include <sys/time.h>
# include <errno.h>
# include <string.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_lst
{
	void			*content;
	struct s_lst	*nextl;
	struct s_lst	*nextr;
}					t_lst;

typedef struct		s_lsto
{
	void			*content;
	struct s_lsto	*next;
}					t_lsto;

typedef struct		s_rep
{
	char			*name;
	char			*path;
	int				val;
}					t_rep;

typedef struct		s_ind
{
	int				indhyphsolo;
	int				indfts;
	int				indexyet;
	int				indexyet2;
	int				indexyet3;
	int				indexyet4;
	int				indhyphen;
	int				indregfile;
	int				inderror;
	int				index1;
	int				indposition;
	int				indtotal;
	int				indone;
	int				indr;
	int				indt;
	int				inda;
	int				indl;
	int				indreverse;
	char			indillegal;
	int				indoption;
	int				ind1;
	int				ind2;
}					t_ind;

typedef	struct		s_sort
{
	int				ind;
	int				(*f)(t_lsto*);
}					t_sort;

typedef	struct		s_loption
{
	int				link;
	int				uname;
	int				gname;
	int				indrdev;
	int				frdevmin;
	int				frdevmaj;
	int				fsize;
	int				day;
	int				hour;
	int				minute;
	int				year;
	int				xattracl;
}					t_loption;

typedef struct		s_numb
{
	int				val;
}					t_numb;

typedef struct		s_head
{
	t_lst			*lst;
}					t_head;

typedef struct		s_stat
{
	char			*id;
	struct stat		stat1;
}					t_stat;

char				*ft_makepath2(char *str1, char *str2);
void				ft_ls_p1(char **av, t_lsto *lstcmd, t_ind *ind);
void				ft_ls_p1_p1(t_lsto *lstcmd, t_ind *ind);
void				ft_ls_p1_p2(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
void				ft_ls_p1_p3(t_lsto *lstcmd, t_ind *ind);
void				ft_ls_p2(char **av, t_lsto **lstcmd);
void				ft_printlist7_p1(t_lsto *lstmp2);
void				ft_printlist_p1(t_lsto *lstmp, t_lsto **lst1,
		t_lsto **lst2);
int					ft_p_illegal(t_ind *ind);
void				ft_ls_run(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd);
int					ft_ls_run_p1(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p1(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p2(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p3(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p4(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p5(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p6(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p7(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_ls_run_p1_p8(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
void				ft_ls_run_p2(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
t_lst				*lst_add(t_lst *toplist, t_lst *lst1);
void				lst_addo(t_lsto **toplist, t_lsto **lst1);
void				lst_addo1(t_lsto ***toplist, t_lsto *lst1);
t_lsto				*lst_addo_down(t_lsto *toplist, t_lsto *lst1);
t_lsto				*lst_addo_down_p1(t_lsto **lst1, t_lsto **lsttopbegi);
t_lsto				*lst_addo_down_p2(t_lsto **lst1, t_lsto **lsttopbegi);
t_lsto				*lst_addo_down_char(t_lsto *toplist, t_lsto *lst1);
t_lsto				*lst_addo_down_char_p1(t_lsto **lst1, t_lsto **lsttopbegi);
t_lsto				*lst_addo_down_char_p2(t_lsto **lst1, t_lsto **lsttopbegi);
t_lsto				*lst_addo_between(t_lsto *toplist, t_lsto *lst1);
void				lst_addo_between_p1(t_lsto *toplist, t_lsto **lst1);
t_lsto				*lst_addo_between_p2(t_lsto **lsttopbegi, t_lsto **lst1);
void				lst_addo_between_p2_p1(t_lsto ***lsttopbegi,
		t_lsto ***lst1);
void				lst_add_del(t_lst **toplist, t_lst **t_lst1);
t_lsto				*ft_create_lsto2(t_rep *rep);
t_lsto				*ft_create_lsto_char2(char *content);
t_lsto				*ft_getprimelist(char **av, t_ind *ind);
t_lsto				*ft_getprimelist2(char **av, t_ind *ind);
t_lsto				*ft_getreplist(char *rep);
t_lsto				*ft_getreplist4(char *rep);
t_lsto				*ft_getreplisto4(t_lsto *lstmp);
void				ft_printlist(t_lsto *lstmp);
t_lsto				*ft_printlist2(t_lsto *lstmp);
t_lsto				*ft_printlist3(t_lsto *lstmp);
void				ft_printlist4(t_lsto *lstmp);
void				ft_printlist5(t_lsto *lstmp);
void				ft_printlist6(t_lsto *lstmp);
void				ft_printlist7(t_lsto *lstmp);
t_lsto				*ft_printlist8(t_lsto *lstmp);
void				ft_printlist9(t_lsto *lstmp);
t_lsto				*ft_printlist10(t_lsto *lstmp);
t_lsto				*ft_printlist11(t_lsto *lstmp);
t_lsto				*ft_printlist12(t_lsto *lstmp);
void				ft_printlist13(t_lsto *lstmp);
void				ft_printlist14(t_lsto *lstmp);
void				ft_printlist15(t_lsto *lstmp);
t_lsto				*ft_printlist16(t_lsto *lstmp);
t_lsto				*ft_printlist17(t_lsto *lstmp);
t_lsto				*ft_printlist18(t_lsto *lstmp);
t_lsto				*ft_printlist19(t_lsto *lstmp);
t_lsto				*ft_printlist20(t_lsto *lstmp);
void				ft_printlist21(t_lsto *lstmp);
t_lsto				*ft_printlist22(t_lsto *lstmp);
t_lsto				*ft_printlist23(t_lsto *lstmp);
void				ft_printlist24(t_lsto *lstmp);
t_lsto				*ft_printlist25(t_lsto *lstmp);
t_lsto				*ft_printlist26(t_lsto *lstmp);
t_lsto				*ft_printlist27(t_lsto *lstmp);
t_lsto				*ft_printlist28(t_lsto *lstmp);
t_lsto				*ft_printlist29(t_lsto *lstmp);
t_lsto				*ft_printlist30(t_lsto *lstmp);
t_lsto				*ft_printlist31(t_lsto *lstmp);
int					ft_countlevel(t_lst *lstmp);
char				*ft_makepath(char *str1, char *str2);
void				ft_push1stback(t_lst **lstmp);
int					ft_countfiles(char *str);
void				ft_addreplist(t_lst **lst1, t_lst *lst2, t_lst **lstname,
		t_lst **lstval);
void				ft_trailrep(t_lst **lst, char *str);
int					croissant(t_lsto *lsta);
int					croissant_char(t_lsto *lsta);
int					croissant_pathname(t_lsto *lsti);
int					ft_isdir(char *s);
int					ft_isreg(char *s);
int					ft_islnk(char *s);
void				ft_init(t_ind *ind);
int					decreasing(t_lsto *lsta);
int					decreasing_char(t_lsto *lsta);
int					croissant_time(t_lsto *lsta);
int					croissant_time_p1(struct stat sa, struct stat sb);
int					croissant_time_char(t_lsto *lsta);
int					decreasing_time(t_lsto *lsta);
int					decreasing_time_p1(struct stat sa, struct stat sb);
int					decreasing_time_char(t_lsto *lsta);
void				ft_t(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_r(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printerror(char **av, t_ind *ind);
void				ft_printerror_p1(char **av, t_ind *ind, t_lsto **lst1,
		t_lsto **lst2);
int					ft_printerror_p1_p1(char **av, t_ind *ind, int i);
void				ft_scan_ind(char **av, t_ind *ind);
void				ft_print_permission(char *s, t_loption loption);
void				ft_print_permission_p1(struct stat sb);
void				ft_print_permission_p2(struct stat sb);
void				ft_print_permission_p3(struct stat sb);
void				ft_print_permission_p4(struct stat sb);
void				ft_printlregfile(t_lsto *lst1);
void				ft_printldir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlrdir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printltdir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
int					ft_check_string(char *s);
void				ft_a(char *s, t_ind *ind);
void				ft_reverse(char *s, t_ind *ind);
void				ft_areverse(char *s, t_ind *ind);
void				ft_at(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_ar(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_atreverse(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_rt(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_rreverse(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_treverse(char *s, t_ind *ind);
void				ft_art(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlardir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printladir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlrtdir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlrreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlatdir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printltreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlareversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_trreverse(char *s, t_ind *ind);
void				ft_trreverse_p1(t_ind *ind);
void				ft_arreverse(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlatreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlartdir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printltrreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlarreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printlatrreversedir(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_atrreverse(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_putlongnbr(long n);
void				ft_putulongnbr(unsigned long n);
void				ft_p0regfile(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd);
void				ft_p0regfile_p1(t_lsto *lst1, t_ind *ind, char *s1,
		int inderror);
void				ft_p0regfile_p2(t_lsto *lst1, t_ind *ind, char *s1,
		int inderror);
void				ft_p0error(t_lsto *lst1, t_ind *ind, t_lsto *lstcmd);
void				ft_p0error_p1(char *s, t_ind *ind, t_lsto *lstcmd);
void				ft_p0error_p1_p1(char *s, t_ind *ind);
void				ft_p0error_p1_p2(t_lsto *lst1, t_ind *ind);
int					ft_getindex(t_lsto *lst1, t_lsto *lstcmd);
int					ft_checkhyphen(t_lsto *lst1, t_lsto *lstcmd, t_ind *ind);
int					ft_checkhyphencase(t_lsto *lst1, t_ind *ind);
int					ft_checkhyphencase_print(t_lsto *lst1, t_ind *ind);
void				ft_printlst(t_lsto *lstmp);
void				ft_printname(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_printname_p1(char *s, t_lsto *lstcmd, t_ind *ind,
		int cnt);
int					ft_printname_p2(char *s, t_lsto *lstcmd, t_ind *ind,
		int cnt);
void				ft_printname_p3(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_print_n(char *s, t_lsto *lstcmd, t_ind *ind);
void				ft_scan_option(char **av, t_ind *ind);
void				ft_scan_option_p1(char **av, t_ind *ind, int i, int j);
int					ft_scan_option2(char *av);
int					ft_scan_option2_p1(char *av, char *l, int j);
void				ft_init2(t_loption *loption);
void				ft_width(t_lsto *lst1, t_loption *loption);
void				ft_width_p1(t_loption *loption, struct stat sb);
void				ft_width_p2(t_loption *loption, struct stat sb,
		time_t curtime);
void				ft_wl(t_lsto *lst1, t_loption loption);
void				ft_wl_p(char *s, t_loption loption, struct stat sb,
		time_t curtime);
void				ft_wl_p0(char *s, t_loption loption, struct stat sb);
void				ft_wl_p1(t_loption loption, struct stat sb);
void				ft_wl_p2(t_loption loption, struct stat sb, time_t curtime);
void				ft_wl_p3(t_loption loption, struct stat sb, time_t curtime);
void				ft_wl_p4(t_loption loption, struct stat sb, time_t curtime);
void				ft_wl_p5(t_loption loption, struct stat sb, time_t curtime);
void				ft_wl_p6(t_lsto *lst1, t_loption loption, struct stat sb,
		time_t curtime);
void				ft_putwidth(char *s, int p);
void				ft_putwidth2(char *s, int p);
void				ft_freelst(t_lsto **lstmp);
void				ft_freelst2(t_lsto **lstmp);
void				ft_wl2(t_lsto *lst1, t_loption loption);
void				ft_width2(t_lsto *lst1, t_loption *loption);
int					ft_checkpermission(char *s);
int					ft_checkslash(char *s);
int					ft_checkokfile(char *s);
int					ft_countelem(t_lsto *lst1);
void				ft_mem1(char **s1, char **s2, t_lsto *lsta);
void				ft_mem1_char(char **s1, char **s2, t_lsto *lsta);
t_lsto				*ft_lst_sort(t_lsto *lst, int (*cmp)(t_lsto*));
void				ft_lst_sort_p1(t_lsto **lst, t_lsto **lstbegi,
		t_lsto **lstmp1, t_sort *s);
void				ft_lst_sort_p2(t_lsto **lst, t_lsto **lstbegi,
		t_lsto **lstmp1, t_sort *s);
void				ft_function_rl(t_lsto **lsti, t_lsto *lst,
		t_lsto *(*f1)(char *), t_lsto *(*f2)(t_lsto *));
void				ft_function_r4(t_lsto **lsti, t_lsto *lst,
		t_lsto *(*f1)(char *), t_lsto *(*f2)(t_lsto *));
void				ft_function_r4_p1(char *s1);
void				ft_lst_fullfield(t_lsto *lst1, t_lsto **lstmp);
void				ft_putmonth(char *s);
void				ft_puttime(char *s);
char				*ft_getday_str(char *s);
void				ft_getday_str_p1(char **s, int *cnt);
char				*ft_getyear_str(char *s);
void				ft_getyear_str_p1(char **s, int *cnt);
char				*ft_getlinkpath(char *s1);
int					ft_checkdir(char *s1);
t_lsto				*ft_copylst1(t_lsto *lstbegi, t_lsto *lsti, t_lsto *lstj);
t_lsto				*ft_curs(t_lsto *lst1, int i);
t_lsto				*lst_addo42(t_lsto *toplist, t_lsto *lst1);
t_lsto				*ft_reverse_lst(t_lsto *lstmp);
void				ft_free2(t_rep **e);
void				ft_putwidth3(char *s, int p);
char				*ft_getnameWithoutSlash(char *s);
int					ft_checkSlashEndCase(char *s);
int					ft_checkLegitFile(char *s);
char				*ft_cutpath_lcaselink(char *s1);
char				*ft_cutname_lcaselink(char *s1);

#endif
