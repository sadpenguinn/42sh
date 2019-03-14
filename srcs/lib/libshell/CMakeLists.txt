cmake_minimum_required(VERSION 3.13)
project(libshell)

set(NAME		shell)
set(INC			../../../includes)
set(LIBFT_INC	../libft/includes)
set(LIBHASH_INC	../libhash/includes)
set(VECTOR_INC	../vector/includes)
set(SRC_LIB		srcs/xglob.c
				srcs/xmatch.c
				srcs/die.c
				srcs/free_str_arr.c
				srcs/print_str_arr.c
				srcs/size_str_arr.c
				srcs/fill_genv.c
				srcs/sputerr.c
				srcs/sputcmderr.c
				srcs/sstrerr.c
				srcs/sgetenv.c
				srcs/ssetenv.c
				srcs/sgetpath.c
				srcs/sunsetenv.c
				srcs/get_cmd_path.c
        		srcs/split_assignments.c srcs/get_file_size.c)

include_directories(${INC})
include_directories(${LIBFT_INC})
include_directories(${LIBHASH_INC})
include_directories(${VECTOR_INC})

add_library(${NAME} STATIC ${SRC_LIB})
