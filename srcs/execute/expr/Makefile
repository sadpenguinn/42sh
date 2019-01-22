# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 18:42:47 by nkertzma          #+#    #+#              #
#    Updated: 2019/01/22 19:43:06 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc expr_arrfunc.c expr_execute.c simple_operators.c ../../parser/expr/*.c ../../libft/libft.a ../../libft/vector/vector.a -I ../../../includes/ -I ../../libft/includes -I ../../libft/vector

clean:
	rm -rf a.out

fclean: clean

re: fclean all
