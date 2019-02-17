cmake_minimum_required(VERSION 3.13)
project(utest)

set(NAME		ut)
set(LIBFT_INC	../libft/includes)
set(SRC_LIB		srcs/ut_init_test.c
				srcs/ut_add_test.c
        		srcs/ut_run_test.c
        		srcs/ut_assert_test.c
        		srcs/ut_clean_test.c
				srcs/internal/ut_ret.c
				srcs/internal/ut_write.c)
include_directories(${LIBFT_INC})

add_library(${NAME} STATIC ${SRC_LIB})
