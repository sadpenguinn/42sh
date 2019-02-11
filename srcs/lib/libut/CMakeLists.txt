cmake_minimum_required(VERSION 3.13)
project(libut)

set(NAME ut)
set(LIBFT_INC ../libft/includes)
set(SRC_LIB srcs/ut_add_test.c
            srcs/ut_assert_test.c
            srcs/ut_clean_test.c
            srcs/ut_run_test.c)
include_directories(includes)
include_directories(${LIBFT_INC})

add_library(${NAME} STATIC ${SRC_LIB})