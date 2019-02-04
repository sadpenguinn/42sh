# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 17:29:19 by nkertzma          #+#    #+#              #
#    Updated: 2019/02/03 11:36:11 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT=lexer
SRC=main.c lexer.c lexer_tools.c trim_quotes.c
OBJ=main.o lexer.o lexer_tools.o trim_quotes.o
INC=../../includes
LIB_SRC=../libft/libft.a
LIB_INC=../libft/includes
VECTOR_SRC=../libft/vector/vector.a
VECTOR_INC=../libft/vector/
FLAGS=-Wall -Wextra -Werror -g

all: $(OUT)

$(OUT):
	gcc -c $(FLAGS) $(SRC) -I $(INC) -I $(LIB_INC) -I $(VECTOR_INC)
	gcc $(FLAGS) $(OBJ) $(LIB_SRC) $(VECTOR_SRC) -I $(INC) -I $(LIB_INC) -I $(VECTOR_INC) -o $(OUT)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OUT)

re: fclean $(OUT)

.PHONY: all clean fclean re
