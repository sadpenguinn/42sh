cmake_minimum_required(VERSION 3.13)
project(libhash)

set(NAME hash)
set(LIBFT_INC ../libft/includes)
set(SHELL_INC ../../../includes)
set(SRC_LIB srcs/hash_clean.c
            srcs/hash_delete.c
            srcs/hash_find.c
            srcs/hash_foreach.c
            srcs/hash_index.c
            srcs/hash_test.c
            srcs/hash_print.c
            srcs/hash_insert.c
            srcs/hash_init.c
			srcs/hash_function_djb2.c
			srcs/hash_function_eq_djb2.c)
include_directories(${LIBFT_INC})
include_directories(${SHELL_INC})

add_library(${NAME} STATIC ${SRC_LIB})
