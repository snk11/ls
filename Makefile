# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/15 21:10:44 by syusof            #+#    #+#              #
#    Updated: 2016/11/13 13:13:55 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ft_a.c ft_areverse.c ft_art.c ft_at.c ft_ar.c ft_arreverse.c \
ft_atreverse.c ft_checkhyphen.c ft_check_string.c ft_atrreverse.c \
ft_checkslash.c ft_countelem.c ft_checkokfile.c ft_checkhyphencase.c \
ft_checkhyphencase_print.c ft_getindex.c ft_freelst.c ft_getprimelist.c \
ft_isdir.c ft_islnk.c ft_isreg.c ft_init.c ft_ls1.c ft_function_r.c \
ft_ls3.c ft_getreplist.c ft_ls2.c ft_ls_run1.c ft_ls_run4.c \
ft_lst_fullfield.c ft_makepath.c ft_mem1.c ft_p0error.c ft_ls_run3.c \
ft_p0error2.c ft_p_illegal.c ft_print_n.c ft_p0regfile.c \
ft_print_permission.c ft_printladir.c ft_printlardir.c \
ft_printlareversedir.c ft_printlarreversedir.c ft_ls_run2.c ft_printlatdir.c \
ft_printerror.c ft_printlatreversedir.c ft_printldir.c ft_printlartdir.c \
ft_printlatrreversedir.c ft_printlist1.c ft_printlist2.c \
ft_printlist3.c ft_printlist4.c ft_printlrdir.c ft_printlregfile.c \
ft_printlreversedir.c ft_printlrreversedir.c ft_printlrtdir.c \
ft_printltdir.c ft_printltreversedir.c ft_printlist7.c \
ft_printltrreversedir.c ft_putlongnbr.c ft_printlist5.c ft_putmonth.c \
ft_putwidth.c ft_r.c ft_reverse.c ft_rreverse.c ft_rt.c ft_scan_ind.c \
ft_sort.c ft_printname.c ft_printlist6.c ft_t.c ft_treverse.c \
ft_trreverse.c ft_scan_option.c ft_width2.c ft_sort3.c ft_width.c ft_sort2.c \
ft_wl1.c ft_wl2.c ft_wl.c function1.c function2.c function3.c \

OFILES = ft_a.o ft_areverse.o ft_art.o ft_at.o ft_ar.o ft_arreverse.o \
ft_atreverse.o ft_checkhyphen.o ft_check_string.o ft_atrreverse.o \
ft_checkslash.o ft_countelem.o ft_checkokfile.o ft_checkhyphencase.o \
ft_checkhyphencase_print.o ft_getindex.o ft_freelst.o ft_getprimelist.o \
ft_isdir.o ft_islnk.o ft_isreg.o ft_init.o ft_ls1.o ft_function_r.o \
ft_ls3.o ft_getreplist.o ft_ls2.o ft_ls_run1.o ft_ls_run4.o \
ft_lst_fullfield.o ft_makepath.o ft_mem1.o ft_p0error.o ft_ls_run3.o \
ft_p0error2.o ft_p_illegal.o ft_print_n.o ft_p0regfile.o \
ft_print_permission.o ft_printladir.o ft_printlardir.o \
ft_printlareversedir.o ft_printlarreversedir.o ft_ls_run2.o ft_printlatdir.o \
ft_printerror.o ft_printlatreversedir.o ft_printldir.o ft_printlartdir.o \
ft_printlatrreversedir.o ft_printlist1.o ft_printlist2.o \
ft_printlist3.o ft_printlist4.o ft_printlrdir.o ft_printlregfile.o \
ft_printlreversedir.o ft_printlrreversedir.o ft_printlrtdir.o \
ft_printltdir.o ft_printltreversedir.o ft_printlist7.o \
ft_printltrreversedir.o ft_putlongnbr.o ft_printlist5.o ft_putmonth.o \
ft_putwidth.o ft_r.o ft_reverse.o ft_rreverse.o ft_rt.o ft_scan_ind.o \
ft_sort.o ft_printname.o ft_printlist6.o ft_t.o ft_treverse.o \
ft_trreverse.o ft_scan_option.o ft_width2.o ft_sort3.o ft_width.o ft_sort2.o \
ft_wl1.o ft_wl2.o ft_wl.o function1.o function2.o function3.o \

FLAGS = -I ./ -I libft/ -c

MAIN = ft_ls.c

OMAIN = ft_ls.o

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAGS) $(MAIN) $(SRCS)
	gcc -o $(NAME) $(OMAIN) $(OFILES) -L libft/ -lft

clean:
	rm -f $(OMAIN) $(OFILES)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
