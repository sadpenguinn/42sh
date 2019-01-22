# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 19:43:14 by nkertzma          #+#    #+#              #
#    Updated: 2019/01/22 13:54:14 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc *.c ../../../srcs/libft/libft.a -I. -I ../../../include -I ../../../srcs/libft/includes/ -I ../../../srcs/libft/vector ../../libft/vector/vector.a

clean:
	rm -rf a.out

fclean: clean

re: all fclean
