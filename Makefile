# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/15 21:10:44 by syusof            #+#    #+#              #
#    Updated: 2015/11/13 06:32:07 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = *.c

OFILES = $(SRCS:.c=.o)

FLAGS = -I push_swap/includes -I libft/includes -c

MAIN = ft_ls.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	make -C push_swap/ re
	gcc $(FLAGS) $(SRCS)
	gcc -o $(NAME) $(OFILES)  -L libft/ -lft

clean:
	rm -f $(OFILES)
	make -C libft/ clean
	make -C push_swap/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C push_swap/ fclean

re: fclean all
