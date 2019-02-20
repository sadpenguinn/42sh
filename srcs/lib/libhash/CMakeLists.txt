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
			srcs/hash_get_size.c
			srcs/hash_get_len.c
			srcs/hash_free_fields.c main.c)
include_directories(${LIBFT_INC})
include_directories(${SHELL_INC})

add_library(${NAME} STATIC ${SRC_LIB})
