cmake_minimum_required(VERSION 3.13)
project(libvector)

set(NAME vector)
set(SRC_LIB srcs/ft_ceill.c
			srcs/ft_floorl.c
			srcs/queue_back.c
			srcs/queue_create.c
			srcs/queue_free.c
			srcs/queue_front.c
			srcs/queue_pop_back.c
			srcs/queue_push_back.c
			srcs/test_main.c
			srcs/vector_back.c
			srcs/vector_create.c
			srcs/vector_foreach.c
			srcs/vector_free.c
			srcs/vector_front.c
			srcs/vector_get_elem.c
			srcs/vector_get_len.c
			srcs/vector_is_empty.c
			srcs/vector_pop_back.c
			srcs/vector_push_back.c
			srcs/vector_to_array.c)
include_directories(includes)

add_library(${NAME} STATIC ${SRC_LIB})
