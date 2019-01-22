# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 19:46:36 by nkertzma          #+#    #+#              #
#    Updated: 2019/01/22 19:46:37 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
LIBFT = libft.a
VECTOR = vector.a
SRC_DIR = ../../srcs/lexer/
INC_DIR = -I ../../includes
LIB_SRC_DIR = ../../srcs/libft/
LIB_INC_DIR = -I ../../srcs/libft/includes
VEC_SRC_DIR = ../../srcs/libft/vector/
VEC_INC_DIR = -I ../../srcs/libft/vector/
TESTS_SRC = lexer_tests.c
FLAGS = -g -O0 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(VECTOR)
	gcc $(FLAGS) $(wildcard $(addprefix $(SRC_DIR), *.c)) $(addprefix $(LIB_SRC_DIR), $(LIBFT)) $(addprefix $(VEC_SRC_DIR), $(VECTOR)) $(TESTS_SRC) $(INC_DIR) $(LIB_INC_DIR) $(VEC_INC_DIR) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_SRC_DIR) all

$(VECTOR):
	$(MAKE) -C $(VEC_SRC_DIR) re

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM

fclean: clean

re: fclean $(NAME)

.PHONY: all clean fclean re
