# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 19:55:48 by bbaelor-          #+#    #+#              #
#    Updated: 2019/02/19 19:44:17 by bbaelor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	extention
SRC_DIR	=	./

SRC		=	extention.c\
			functions_to_write.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/check_valid_of_variable.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/check_varname.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/die.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/free_str_arr.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/glob.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/match.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/print_str_arr.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/sgetenv.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/split_env.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/sputerr.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/ssetenv.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/sstrerr.c\
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/sunsetenv.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init_env.c\
			/Users/bbaelor-/42_to_commit_2/srcs/shell/init_path.c

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
			/Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/libhash.a

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
