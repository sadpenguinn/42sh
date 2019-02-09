# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 18:43:26 by bwerewol          #+#    #+#              #
#    Updated: 2019/02/09 19:07:03 by bwerewol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	parser
SRC_DIR	=	./

SRC		=	./main.c\
			./print_astree.c\
			./parseerror.c\
			./check_words.c\
			./freeastree.c\
			./savecur.c\
			./otherfunc.c\
			./simple_command.c\
			./simple_command_element.c\
			./for_command.c\
			./case_command.c\
			./case_clause.c\
			./case_clause_sequence.c\
			./pattern_list.c\
			./pattern.c\
			./function_def.c\
			./function_body.c\
			./compound_list.c\
			./simple_list_terminator.c\
			./list_terminator.c\
			./newline_list.c\
			./word_list.c\
			./redirection_list.c\
			./redirection.c\
			./io_file.c\
			./filename.c\
			./io_here.c\
			./here_end.c
OBJ		=	$(SRC:.c=.o)

CC		?=	gcc
CFLAGS	=	-Wall -Wextra -Werror
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
