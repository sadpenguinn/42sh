# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 19:55:48 by bbaelor-          #+#    #+#              #
#    Updated: 2019/02/23 17:59:06 by bbaelor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	extention
SRC_DIR	=	./

SRC		=	extention.c\
			functions_to_write.c\
			strsplit_for_extention.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init_env.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init_path.c\
			../../lib/libshell/srcs/check_valid_of_variable.c\
			../../lib/libshell/srcs/check_varname.c\
			../../lib/libshell/srcs/die.c\
			../../lib/libshell/srcs/free_str_arr.c\
			../../lib/libshell/srcs/glob.c\
			../../lib/libshell/srcs/match.c\
			../../lib/libshell/srcs/print_str_arr.c\
			../../lib/libshell/srcs/sgetenv.c\
			../../lib/libshell/srcs/split_env.c\
			../../lib/libshell/srcs/sputerr.c\
			../../lib/libshell/srcs/ssetenv.c\
			../../lib/libshell/srcs/sstrerr.c\
			../../lib/libshell/srcs/sunsetenv.c

OBJ		=	$(SRC:.c=.o)

CC		?=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-std=c11
INCLUDES=	-I../../libft/includes -I../../libft/vector -I../../../includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libft/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/vector/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libstring/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/includes\
			-I/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/includes
CFLAGS	+=	-O0

OTHERSRC=	/Users/bbaelor-/42_to_commit_2/srcs/lib/libft/libft.a\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/vector/libvector.a\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/libhash.a\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/libshell.a

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
