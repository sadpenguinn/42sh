# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 17:40:13 by bbaelor-          #+#    #+#              #
#    Updated: 2019/02/14 18:28:33 by bbaelor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	exec
SRC_DIR	=	./

SRC		=	../parser/main.c\
			../parser/print_astree.c\
			../parser/parseerror.c\
			../parser/check_words.c\
			../parser/freeastree.c\
			../parser/savecur.c\
			../parser/otherfunc.c\
			../parser/simple_command.c\
			../parser/simple_command_element.c\
			../parser/for_command.c\
			../parser/case_command.c\
			../parser/case_clause.c\
			../parser/case_clause_sequence.c\
			../parser/pattern_list.c\
			../parser/pattern.c\
			../parser/if_command.c\
			../parser/elif_clause.c\
			../parser/subshell.c\
			../parser/arith_command.c\
			../parser/function_def.c\
			../parser/function_body.c\
			../parser/compound_list.c\
			../parser/simple_list_terminator.c\
			../parser/list_terminator.c\
			../parser/newline_list.c\
			../parser/word_list.c\
			../parser/redirection_list.c\
			../parser/redirection.c\
			../parser/io_file.c\
			../parser/filename.c\
			../parser/io_here.c\
			../parser/here_end.c\
			./execcmd.c\
			./debug.c\
			./functoins_to_write.c
OBJ		=	$(SRC:.c=.o)

CC		?=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-std=c11
INCLUDES=	-I../libft/includes -I../libft/vector -I../../includes
CFLAGS	+=	-O0
OTHERSRC=	../libft/libft.a ../xmalloc/xmalloc.c ../libft/vector/vector.a

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
