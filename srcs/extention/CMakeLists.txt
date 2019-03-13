cmake_minimum_required(VERSION 3.13)
project(expand)

set(SRC				extention.c
					get_true_format.c
					strsplit_for_extention.c
					debug_and_main.c
					strins_sheets.c
					psevdo_functions.c
					configurate_of_exptention.c
					configure_remalloc.c
					stars.c
					../shell/init.c
					../shell/init_env.c
					../shell/init_path.c
					../lib/libshell/srcs/check_valid_of_variable.c
					../lib/libshell/srcs/check_varname.c
					../lib/libshell/srcs/die.c
					../lib/libshell/srcs/free_str_arr.c
					../lib/libshell/srcs/glob.c
					../lib/libshell/srcs/match.c
					../lib/libshell/srcs/print_str_arr.c
					../lib/libshell/srcs/sgetenv.c
        ../lib/libshell/srcs/split_assignments.c
					../lib/libshell/srcs/sputerr.c
					../lib/libshell/srcs/ssetenv.c
					../lib/libshell/srcs/sstrerr.c
					../lib/libshell/srcs/sunsetenv.c
					../shell/argv_parser.c
					../shell/destroy.c
					../shell/destroy_env.c
					../shell/destroy_jobs.c
					../shell/destroy_path.c
					../shell/destroy_process.c
					../shell/init.c
					../shell/init_env.c
					../shell/init_jobs.c
					../shell/init_path.c
					../shell/init_process.c
					../shell/signals.c
					../shell.c
					../execute/process.c
					)

set(INC				../libft/includes
					../libft/vector
					../../includes
					../lib/libft/includes
					../lib/vector/includes
					../lib/libstring/includes
					../lib/libhash/includes
					../lib/libshell/includes
					../parser
					)

SET(CMAKE_C_FLAGS 	"${CMAKE_C_FLAGS} -g -Wall -Wextra -Werror")

include_directories(${INC})

add_library(libft.a SHARED IMPORTED)
set_target_properties(libft.a PROPERTIES IMPORTED_LOCATION ../lib/libft/libft.a)

add_library(libvector.a SHARED IMPORTED)
set_target_properties(libvector.a PROPERTIES IMPORTED_LOCATION ../lib/vector/libvector.a)

add_library(libhash.a SHARED IMPORTED)
set_target_properties(libhash.a PROPERTIES IMPORTED_LOCATION ../lib/libhash/libhash.a)

add_library(libshell.a SHARED IMPORTED)
set_target_properties(libshell.a PROPERTIES IMPORTED_LOCATION ../lib/libshell/libshell.a)

add_executable(extention ${SRC})
target_link_libraries(extention libft.a libvector.a libshell.a libhash.a)
