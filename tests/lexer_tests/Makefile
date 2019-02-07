# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 19:46:36 by nkertzma          #+#    #+#              #
#    Updated: 2019/02/06 20:04:26 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
LEXER_SRC_DIR = ../../srcs/lexer/
LEXER_SRC = lexer.c lexer_tools.c trim_quotes.c
INC_DIR = -I ../../includes
LIBFT = libft.a
LIB_SRC_DIR = ../../srcs/libft/
LIB_INC_DIR = -I ../../srcs/libft/includes
VECTOR = vector.a
VEC_SRC_DIR = ../../srcs/libft/vector/
VEC_INC_DIR = -I ../../srcs/libft/vector/
UTEST = utest.a
UT_SRC_DIR = ../../srcs/libft/utest/
UT_INC_DIR = -I ../../srcs/libft/utest/
TESTS_SRC = lexer_tests.c trim_quotes_tests.c
# FLAGS = -g -O0 -Wall -Wextra -Werror
FLAGS = -g -O0
RE_DEPENDENCIES = False

all: $(NAME)

$(NAME): $(LIBFT) $(VECTOR) $(UTEST)
	gcc $(FLAGS) $(wildcard $(addprefix $(LEXER_SRC_DIR), $(LEXER_SRC))) $(addprefix $(LIB_SRC_DIR), $(LIBFT)) $(addprefix $(VEC_SRC_DIR), $(VECTOR)) $(addprefix $(UT_SRC_DIR), $(UTEST)) $(TESTS_SRC) $(INC_DIR) $(LIB_INC_DIR) $(VEC_INC_DIR) $(UT_INC_DIR) -o $(NAME)

$(LIBFT):
ifeq ($(RE_DEPENDENCIES), True)
	$(MAKE) -C $(LIB_SRC_DIR) re
else
	@$(MAKE) -C $(LIB_SRC_DIR)
endif

$(VECTOR):
ifeq ($(RE_DEPENDENCIES), True)
	$(MAKE) -C $(VEC_SRC_DIR) re
else
	@$(MAKE) -C $(VEC_SRC_DIR)
endif

$(UTEST):
ifeq ($(RE_DEPENDENCIES), True)
	$(MAKE) -C $(UT_SRC_DIR) re
else
	@$(MAKE) -C $(UT_SRC_DIR)
endif

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM

fclean: clean

re: fclean $(NAME)

.PHONY: all clean fclean re
