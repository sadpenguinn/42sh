cmake_minimum_required(VERSION 3.13)
project(libstring)

set(NAME		string)
set(INC			includes)
set(LIBFT_INC	../libft/includes)
set(SRC_LIB 	srcs/string_init.c
				srcs/string_resize.c
				srcs/string_insert.c
				srcs/string_join.c
				srcs/string_push.c
				srcs/string_free.c)
include_directories(${INC})
include_directories(${LIBFT_INC})

add_library(${NAME} STATIC ${SRC_LIB})