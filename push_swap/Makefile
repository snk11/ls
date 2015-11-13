# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/31 19:17:09 by syusof            #+#    #+#              #
#    Updated: 2015/06/12 20:51:48 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = *.c

OFILES = $(SRCS:.c=.o)

FLAGS = -I libft/includes/ -c

MAIN = push_swap.c

OMAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc $(FLAGS) $(SRCS)
	gcc -o $(NAME) $(OFILES)  -L libft/ -lft

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
