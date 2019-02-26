cmake_minimum_required(VERSION 3.13)
project(42sh LANGUAGES C)

set(NAME			42sh)
set(INC				includes)
set(PARSER_INC		srcs/parser)
set(LIBFT			ft)
set(LIBFT_DIR		srcs/lib/libft)
set(LIBFT_INC		srcs/lib/libft/includes)
set(LIBHASH			hash)
set(LIBHASH_DIR		srcs/lib/libhash)
set(LIBHASH_INC		srcs/lib/libhash/includes)
set(VECTOR			vector)
set(VECTOR_DIR		srcs/lib/vector)
set(VECTOR_INC		srcs/lib/vector/includes)
set(LIBSHELL		shell)
set(LIBSHELL_DIR	srcs/lib/libshell)
set(CMAKE_C_FLAGS 	"${CMAKE_C_FLAGS} -g -Wall -Wextra -Werror")

set(MAIN			srcs/shell.c)

set(EXEC_SRC		srcs/execute/parser/errors.c
					srcs/execute/parser/execcmd.c
					srcs/execute/parser/execfunc.c
					srcs/execute/parser/execlist1.c
					srcs/execute/parser/execlist2.c
					srcs/execute/parser/execlist3.c
					srcs/execute/parser/execpipecmd.c
					srcs/execute/parser/execpipes.c
					srcs/execute/parser/execscmd.c
					srcs/execute/parser/execshellcmd.c
					srcs/execute/parser/execcase.c
					srcs/execute/parser/execif.c
					srcs/execute/parser/execsubshell.c
					srcs/execute/parser/execute.c
					srcs/execute/parser/getredir.c)

set(SHELL_SRC		srcs/shell/init.c
					srcs/shell/init_env.c
					srcs/shell/init_path.c
					srcs/shell/destroy.c
					srcs/shell/destroy_env.c
					srcs/shell/destroy_path.c
					srcs/shell/init_jobs.c
					srcs/shell/init_process.c
					srcs/shell/destroy_jobs.c
					srcs/shell/destroy_process.c
					srcs/shell/signals.c
					srcs/shell/argv_parser.c)

set(READLINE_SRC 	srcs/readline/readline.c
					srcs/readline/array.c
					srcs/readline/check_next_symbol.c
					srcs/readline/term.c
					srcs/readline/prompt.c
					srcs/readline/inits.c
					srcs/readline/resize_windows.c
					srcs/readline/matrix_resize.c
					srcs/readline/line_resize.c
					srcs/readline/move_cursor_1.c
					srcs/readline/move_cursor_2.c
					srcs/readline/check_esc_code.c
					srcs/readline/matrix_string_insert.c
					srcs/readline/matrix_create_line.c
					srcs/readline/utf.c
					srcs/readline/matrix_string_delete.c
					srcs/readline/buttons1.c
					srcs/readline/matrix_erase_line.c
					srcs/readline/readline_memdel.c
					srcs/readline/get_next_symbol.c
					srcs/readline/move_shortcuts.c
					srcs/readline/newline_handling.c
					srcs/readline/add_style.c
					srcs/readline/add_text.c
					srcs/readline/symbol_to_string.c
					srcs/readline/set_matrix_limits.c
					srcs/readline/matrix_to_string.c
					srcs/readline/count_string_objects.c
					srcs/readline/print.c
					srcs/readline/readline_mode.c
					srcs/readline/add_cursor_offset.c
					srcs/readline/add_line_prefix.c
					srcs/readline/get_lines_info.c)

set(BUILTIN_SRC		srcs/builtins/built_cd.c
					srcs/builtins/built_echo.c
					srcs/builtins/built_env.c
					srcs/builtins/built_setenv.c
					srcs/builtins/built_unsetenv.c
					srcs/builtins/built_exit.c)

set(LEXER_SRC		srcs/lexer/lexer.c
					srcs/lexer/lexer_tools.c)

set(PARSER_SRC		srcs/parser/arith_command.c
					srcs/parser/arith_for_command.c
					srcs/parser/case_clause.c
					srcs/parser/case_clause_sequence.c
					srcs/parser/case_command.c
					srcs/parser/check_words.c
					srcs/parser/command.c
					srcs/parser/compound_list.c
					srcs/parser/cond_command.c
					srcs/parser/elif_clause.c
					srcs/parser/filename.c
					srcs/parser/for_command.c
					srcs/parser/freeastree.c
					srcs/parser/function_body.c
					srcs/parser/function_def.c
					srcs/parser/group_command.c
					srcs/parser/here_end.c
					srcs/parser/if_command.c
					srcs/parser/inpuntunit.c
					srcs/parser/print_astree.c
					srcs/parser/io_file.c
					srcs/parser/io_here.c
					srcs/parser/list1.c
					srcs/parser/list2.c
					srcs/parser/list3.c
					srcs/parser/list_terminator.c
					srcs/parser/newline_list.c
					srcs/parser/otherfunc.c
					srcs/parser/parseerror.c
					srcs/parser/pattern.c
					srcs/parser/pattern_list.c
					srcs/parser/pipeline.c
					srcs/parser/pipeline_command.c
					srcs/parser/print_astree.c
					srcs/parser/redirection.c
					srcs/parser/redirection_list.c
					srcs/parser/savecur.c
					srcs/parser/select_command.c
					srcs/parser/shell_command.c
					srcs/parser/simple_command.c
					srcs/parser/simple_command_element.c
					srcs/parser/simple_list1.c
					srcs/parser/simple_list2.c
					srcs/parser/simple_list3.c
					srcs/parser/simple_list_terminator.c
					srcs/parser/subshell.c
					srcs/parser/word_list.c)

include_directories(${INC})
include_directories(${PARSER_INC})
include_directories(${LIBFT_INC})
include_directories(${LIBHASH_INC})
include_directories(${VECTOR_INC})

add_subdirectory(${LIBFT_DIR})
add_subdirectory(${LIBHASH_DIR})
add_subdirectory(${VECTOR_DIR})
add_subdirectory(${LIBSHELL_DIR})

add_executable(42sh ${MAIN} ${SHELL_SRC} ${LIBSHELL_SRC} ${BUILTIN_SRC} ${READLINE_SRC} ${LEXER_SRC} ${PARSER_SRC} ${EXEC_SRC})
target_link_libraries(42sh ${LIBFT} ${LIBHASH} ${VECTOR} ${LIBSHELL})
