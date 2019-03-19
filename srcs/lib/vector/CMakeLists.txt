cmake_minimum_required(VERSION 3.13)
project(libvector)

set(NAME vector)
set(LIBFT_INC ../libft/includes)
set(SRC_LIB srcs/vector_back.c
			srcs/vector_create.c
			srcs/vector_foreach.c
			srcs/vector_free.c
			srcs/vector_front.c
			srcs/vector_get_elem.c
			srcs/vector_get_len.c
			srcs/vector_is_empty.c
			srcs/vector_pop_back.c
			srcs/vector_del_elem.c
			srcs/vector_push_back.c
			srcs/vector_to_array.c
			srcs/ft_ceil.c
			srcs/ft_floorl.c)
include_directories(includes)
include_directories(${LIBFT_INC})

add_library(${NAME} STATIC ${SRC_LIB})
