# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 18:42:47 by nkertzma          #+#    #+#              #
#    Updated: 2019/01/23 11:18:34 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc expr_arrfunc.c expr_execute.c math_operators.c bits_operators.c logical_operators.c assign_operators.c ../../parser/expr/*.c ../../libft/libft.a ../../libft/vector/vector.a -I ../../../includes/ -I ../../libft/includes -I ../../libft/vector

clean:
	rm -rf a.out

fclean: clean

re: fclean all
