cmake_minimum_required(VERSION 3.13)
project(libalias)

set(NAME alias)
set(LIBFT_INC ../libft/includes)
set(SHELL_INC ../../../includes)
set(SRC_LIB srcs/alias_clean.c
            srcs/alias_delete.c
            srcs/alias_find.c
            srcs/alias_foreach.c
            srcs/alias_index.c
            srcs/alias_insert.c
            srcs/alias_search.c
            srcs/alias_init.c
            srcs/alias_realloc.c
            srcs/alias_free_fields.c
            srcs/alias_tools.c)
include_directories(${LIBFT_INC})
include_directories(${SHELL_INC})

add_library(${NAME} STATIC ${SRC_LIB})
