# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 16:20:46 by bwerewol          #+#    #+#              #
#    Updated: 2018/12/25 18:02:04 by bwerewol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME = libft.a
SRC_DIR	= ./srcs
ASM_DIR = ./asmsrcs
INC_DIR = ./includes
OBJ_DIR	= ./objs

RAW_SRC	:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_ASM	:= $(shell find $(ASM_DIR) -type f | grep -E "\.s$$")
SRC		= $(RAW_SRC:$(SRC_DIR)/%=%)
ASM		= $(RAW_ASM:$(ASM_DIR)/%=%)
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ		+= $(addprefix $(OBJ_DIR)/,$(ASM:.s=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDES=	-I $(INC_DIR)
CFLAGS	+=	-O3

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(FT_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)/%.o:$(ASM_DIR)/%.s
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_NAME): $(OBJ)
	ar rc $(FT_NAME) $(OBJ)
	ranlib $(FT_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT_NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
