# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syusof <syusof@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/31 19:17:09 by syusof            #+#    #+#              #
#    Updated: 2015/11/13 06:31:29 by syusof           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = *.o

SRCS = *.c

OFILES = $(SRCS:.c=.o)

FLAGS = -I ../libft/includes/ -I ../includes -c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)

clean:
	rm -f $(OFILES)

fclean: clean

re: fclean all
