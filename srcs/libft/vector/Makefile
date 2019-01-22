# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: narchiba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 07:17:28 by narchiba          #+#    #+#              #
#    Updated: 2019/01/17 20:08:10 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./
NAME = vector.a
INCLUDE = ./
CF = -Wall -Wextra -Werror
TEST = main_test.c

SRCS = $(SRC)/vector_create.c\
	   $(SRC)/vector_free.c\
	   $(SRC)/vector_push_back.c\
	   $(SRC)/vector_pop_back.c\
	   $(SRC)/vector_back.c\
	   $(SRC)/vector_front.c\
	   $(SRC)/vector_is_empty.c\
	   $(SRC)/ft_ceill.c\
	   $(SRC)/ft_floorl.c\
	   $(SRC)/vector_get_len.c\
	   $(SRC)/vector_get_elem.c\
	   $(SRC)/vector_to_array.c\
	   $(SRC)/vector_foreach.c\
	   $(SRC)/queue_create.c\
	   $(SRC)/queue_free.c\
	   $(SRC)/queue_push_back.c\
	   $(SRC)/queue_pop_back.c\
	   $(SRC)/queue_back.c\
	   $(SRC)/queue_front.c\

OBJS = vector_create.o\
	   vector_free.o\
	   vector_push_back.o\
	   vector_pop_back.o\
	   vector_back.o\
	   vector_front.o\
	   vector_is_empty.o\
	   ft_floorl.o\
	   ft_ceill.o\
	   vector_get_len.o\
	   vector_get_elem.o\
	   vector_to_array.o\
	   vector_foreach.o\
	   queue_create.o\
	   queue_free.o\
	   queue_push_back.o\
	   queue_pop_back.o\
	   queue_back.o\
	   queue_front.o\

all: $(NAME)

$(NAME):
	gcc $(CF) -c $(SRCS) -I $(INCLUDE)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

test: re
	gcc $(CF) test_main.c $(NAME) -I includes/
	./a.out

test_v: re
	gcc $(CF) test_main.c $(NAME) -I includes/
	valgrind ./a.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
