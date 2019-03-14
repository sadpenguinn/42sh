# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 18:13:10 by bbaelor-          #+#    #+#              #
#    Updated: 2019/03/14 17:03:06 by bbaelor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = conditions.c main_and_debug.c

NAME = conditions

INCLUDES = ../../includes

INC_LIB = ../lib/libft/includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -g $(SRC) -o $(NAME) -I $(INCLUDES) -I $(INC_LIB)

re:
	@rm -Rf $(NAME)
	@make $(NAME)