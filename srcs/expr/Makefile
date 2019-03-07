
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 18:43:26 by bwerewol          #+#    #+#              #
#    Updated: 2019/02/20 21:24:11 by bwerewol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME =	expression.out
SRC_DIR	=	./

SRC		=	./exprparser/expr.c\
				./exprparser/expr1.c\
				./exprparser/expr2.c\
				./exprparser/expr3.c\
				./exprparser/expr4.c\
				./exprparser/expr5.c\
				./exprparser/expr6.c\
				./exprparser/expr7.c\
				./exprparser/expr8.c\
				./exprparser/expr9.c\
				./exprparser/expr10.c\
				./exprparser/expr11.c\
				./exprparser/expr12.c\
				./exprparser/expr13.c\
				./exprparser/expr14.c\
				./exprparser/preunary.c\
				./exprparser/operand.c\
				./exprparser/preincdec.c\
				./exprparser/postincdec.c\
				./exprparser/variable.c\
				./exprparser/otherfunc.c\
				./exprparser/print_astree.c

SRC		+= ./expression.c

SRC		+= ./exprlexer/exprlexer.c

SRC		+= ./exprcalc/calc.c\
				 ./exprcalc/calcerror.c\
				 ./exprcalc/math_operators.c\
				 ./exprcalc/logical_operators.c\
				 ./exprcalc/bits_operators.c\
				 ./exprcalc/calcarray.c

OTHERSRC=	../lib/libft/libft.a ../lib/vector/libvector.a ../lib/libshell/libshell.a ../lexer/lexer_tools.c

OBJ		=	$(SRC:.c=.o)

CC		?=	gcc
# CFLAGS	=	-Wall -Wextra -Werror
INCLUDES=	-I../lib/libft/includes -I../lib/vector/includes -I../../includes -I../lib/libhash/includes -I../lib/libstring/includes -I./ -I./exprcalc -I./exprlexer -I./exprparser
CFLAGS	+=	-O0 -g

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
