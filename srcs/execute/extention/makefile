# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 19:55:48 by bbaelor-          #+#    #+#              #
#    Updated: 2019/02/19 18:34:12 by bbaelor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	extention
SRC_DIR	=	./

SRC		=	extention.c functions_to_write.c
OBJ		=	$(SRC:.c=.o)

CC		?=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-std=c11
INCLUDES=	-I../../libft/includes -I../../libft/vector -I../../../includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libft/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/vector/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libstring/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/includes
CFLAGS	+=	-O0
OTHERSRC=	/Users/bbaelor-/42_to_commit_2/srcs/lib/libft/libft.a\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/vector/libvector.a

.PHONY: all clean fclean re

all: $(FT_NAME)

%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(OTHERSRC) $(INCLUDES) -o $(FT_NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(FT_NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
