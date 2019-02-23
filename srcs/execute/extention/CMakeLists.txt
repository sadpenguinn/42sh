cmake_minimum_required(VERSION 3.13)
project(extention)

set(SRC				extention.c
					functions_to_write.c
					strsplit_for_extention.c
					/Users/bbaelor-/42_to_commit_2/srcs/shell/init.c
					/Users/bbaelor-/42_to_commit_2/srcs/shell/init_env.c
					/Users/bbaelor-/42_to_commit_2/srcs/shell/init_path.c
					../../lib/libshell/srcs/check_valid_of_variable.c
					../../lib/libshell/srcs/check_varname.c
					../../lib/libshell/srcs/die.c
					../../lib/libshell/srcs/free_str_arr.c
					../../lib/libshell/srcs/glob.c
					../../lib/libshell/srcs/match.c
					../../lib/libshell/srcs/print_str_arr.c
					../../lib/libshell/srcs/sgetenv.c
					../../lib/libshell/srcs/split_env.c
					../../lib/libshell/srcs/sputerr.c
					../../lib/libshell/srcs/ssetenv.c
					../../lib/libshell/srcs/sstrerr.c
					../../lib/libshell/srcs/sunsetenv.c)

set(INC				../../libft/includes
					../../libft/vector
					../../../includes
					/Users/bbaelor-/42_to_commit_2/srcs/lib/libft/includes
					/Users/bbaelor-/42_to_commit_2/srcs/lib/vector/includes
					/Users/bbaelor-/42_to_commit_2/srcs/lib/libstring/includes
					/Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/includes
					/Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/includes)

include_directories(${INC})

add_library(libft.a SHARED IMPORTED)
set_target_properties(libft.a PROPERTIES IMPORTED_LOCATION /Users/bbaelor-/42_to_commit_2/srcs/lib/libft/libft.a)

add_library(libvector.a SHARED IMPORTED)
set_target_properties(libvector.a PROPERTIES IMPORTED_LOCATION /Users/bbaelor-/42_to_commit_2/srcs/lib/vector/libvector.a)

add_library(libhash.a SHARED IMPORTED)
set_target_properties(libhash.a PROPERTIES IMPORTED_LOCATION /Users/bbaelor-/42_to_commit_2/srcs/lib/libhash/libhash.a)

add_library(libshell.a SHARED IMPORTED)
set_target_properties(libshell.a PROPERTIES IMPORTED_LOCATION /Users/bbaelor-/42_to_commit_2/srcs/lib/libshell/libshell.a)

add_executable(extention ${SRC})
target_link_libraries(extention libft.a libvector.a libshell.a libhash.a)
