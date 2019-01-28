# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: narchiba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 07:17:28 by narchiba          #+#    #+#              #
#    Updated: 2019/01/28 20:23:38 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utest.a
SRCS=ut_add_test.c ut_assert_test.c ut_clean_test.c ut_run_test.c
INC=../includes
OBJS=ut_add_test.o ut_assert_test.o ut_clean_test.o ut_run_test.o
FLAGS = -g -O0 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I $(INC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
