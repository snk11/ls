# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/15 21:10:44 by syusof            #+#    #+#              #
#    Updated: 2016/11/13 13:05:21 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ft_a.c ft_areverse.c ft_art.c ft_at.c ft_ar.c ft_arreverse.c \
ft_atreverse.c ft_checkhyphen.c ft_check_string.c ft_atrreverse.c \
ft_checkslash.c ft_countelem.c ft_checkokfile.c ft_checkhyphencase.c \
ft_checkhyphencase_print.c ft_getindex.c ft_freelst.c ft_getprimelist.c \
ft_isdir.c ft_islnk.c ft_isreg.c ft_init.c ft_ls.c ft_ls1.c ft_function_r.c \
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


OFILES = $(SRCS:.c=.o)

FLAGS = -I ./ -I libft/ -c

MAIN = ft_ls.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAGS) $(SRCS)
	gcc -o $(NAME) $(OFILES) -L libft/ -lft

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
