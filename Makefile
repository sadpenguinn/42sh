# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by dmorgil           #+#    #+#              #
#    Updated: 2019/01/19 12:15:01 by bwerewol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME             ?= 42sh
INC_DIR           = include
SRC_DIR           = srcs
OBJ_DIR          ?= objs
RAW_SRC	         :=	lexer/lexer.c lexer/lexer_tools.c. lexer/trim_quotes.c \
					parser/command.c parser/for_command.c parser/main.c \
					parser/newline_list.c parser/parser.c parser/pipeline.c \
					parser/pipline_command.c parser/redirection_list.c \
					parser/redirection_list.c parser/shell_command.c \
					parser/simple_command.c parser/simple_command_element.c \
					parser/simple_list.c parser/simple_list1.c
RAW_OBJS          = $(RAW_SRC:.c=.o)
SRCS              = $(addprefix $(SRC_DIR)/,$(RAW_SRC))
OBJS              = $(addprefix $(OBJ_DIR)/,$(RAW_OBJS))
INC               = $(addprefix -I, $(INC_DIR) $(addsuffix /include, libft))
OBJS_CLEAN        = $(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN        = $(strip $(foreach f,$(NAME),$(wildcard $(f))))
LIB			      =	srcs/libft/libft.a
FLAGS		      =	-Wall -Wextra -Werror -O3 -Ofast

RED			      =	\033[0;31m
GREEN		      =	\033[0;32m
NC			      =	\033[0m

PRINTF=test $(VERBOSE)$(TRAVIS) || printf

.PHONY: all clean fclean re

all: $(OBJ_DIR)
	make -C srcs/libft
	make -C srcs/libft/vector
	@$(PRINTF) "%-20s" "$(NAME): exe"
	+$(MAKE) -j4 $(NAME) "CFLAGS = $(FLAGS)" "OBJ_PATH = $(OBJ_DIR)"
	@$(PRINTF) "\r\x1b[20C\x1b[0K\x1b[32m✔\x1b[0m\n"

$(OBJ_DIR):
	mkdir -p $(dir $(OBJS))

$(NAME): $(OBJS)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	gcc $(FLAGS) $(INC) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$<"
	@gcc $(INC) $(FLAGS) -MMD -MP -o $@ -c $<

clean:
	make clean -C srcs/libft
	make clean -C srcs/libft/vector
	@rm -rf $(OBJ_DIR)
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

fclean: clean
	make fclean -C srcs/libft
	make fclean -C srcs/libft/vector
	rm -f $(NAME){,.san,.dev}
	@$(PRINTF) "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

re: fclean all

ifndef VERBOSE
 ifndef TRAVIS
  .SILENT:
 endif
endif
