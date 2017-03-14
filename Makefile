# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/15 21:10:44 by syusof            #+#    #+#              #
#    Updated: 2017/03/14 16:09:20 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/libft.a

OBJ = ft_ls.o ft_a.o ft_areverse.o ft_art.o ft_at.o ft_ar.o ft_arreverse.o \
ft_atreverse.o  ft_check_string.o ft_atrreverse.o \
ft_checkslash.o ft_countelem.o ft_checkokfile.o \
ft_getindex.o ft_getprimelist.o \
ft_isdir.o ft_islnk.o ft_isreg.o ft_init.o ft_ls1.o ft_function_r.o \
ft_ls3.o ft_getreplist.o ft_ls2.o ft_ls_run1.o ft_ls_run4.o \
ft_makepath.o ft_mem1.o ft_p0error.o ft_ls_run3.o \
ft_p0error2.o ft_p_illegal.o ft_print_n.o ft_p0regfile.o \
ft_print_permission.o ft_print_permission2.o ft_printladir.o ft_printlardir.o \
ft_printlareversedir.o ft_printlarreversedir.o ft_ls_run2.o ft_printlatdir.o \
ft_printerror.o ft_printlatreversedir.o ft_printldir.o ft_printlartdir.o \
ft_printlatrreversedir.o ft_printlist1.o ft_printlist2.o \
ft_printlist3.o ft_printlist4.o ft_printlrdir.o ft_printlregfile.o \
ft_printlreversedir.o ft_printlrreversedir.o ft_puttime.o ft_printlrtdir.o \
ft_printltdir.o ft_printltreversedir.o ft_printlist7.o \
ft_printltrreversedir.o ft_putlongnbr.o ft_printlist5.o ft_putmonth.o \
ft_putwidth.o ft_r.o ft_reverse.o ft_rreverse.o ft_rt.o \
ft_sort.o ft_printname.o ft_printlist6.o ft_t.o ft_treverse.o \
ft_trreverse.o ft_scan_option.o ft_width2.o ft_sort3.o ft_width.o ft_sort2.o \
ft_wl1.o ft_wl2.o ft_wl.o function1.o function2.o function3.o \
ft_getyear_str.o ft_getday_str.o ft_getlinkpath.o ft_checkdir.o \
ft_curs.o ft_freelst.o ft_getname_without_slash.o ft_check_slash_end_case.o \
ft_check_legit_file.o ft_cutname_lcaselink.o ft_cutpath_lcaselink.o \
ft_printlist8.o ft_wl22.o ft_printl_link.o ft_sort4.o ft_checkdev.o \
ft_p0error_getrep.o

FLAGS = 

MAIN = ft_ls.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "-- done --"

$(LIB):
	@make -C libft/

%.o: %.c
		@gcc $(FLAGS) -I libft/ -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
