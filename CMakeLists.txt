cmake_minimum_required(VERSION 3.13)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In-source builds not allowed. Please make a new directory" )
endif()

set(PROJECT			42sh)
set(VERSION			1.0)
project(${PROJECT}	VERSION ${VERSION} LANGUAGES C)

set(NAME			${PROJECT})
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

if (APPLE)
	set(CMAKE_C_FLAGS 	"${CMAKE_C_FLAGS} -g -Wall -Wextra -Werror")
elseif (UNIX)
	set(CMAKE_C_FLAGS 	"${CMAKE_C_FLAGS} -g -Wall -Wextra")
else ()
	set(CMAKE_C_FLAGS 	"${CMAKE_C_FLAGS} -g")
endif()


set(MAIN			srcs/shell.c)

set(SHELL_SRC		srcs/shell/init.c
					srcs/shell/init_env.c
					srcs/shell/init_path.c
					srcs/shell/destroy.c
					srcs/shell/destroy_env.c
					srcs/shell/destroy_path.c
					srcs/shell/destroy_pids.c
					srcs/shell/init_pids.c
					srcs/shell/init_jobs.c
					srcs/shell/init_process.c
					srcs/shell/destroy_jobs.c
					srcs/shell/destroy_process.c
					srcs/shell/signals.c
					srcs/shell/argv_parser.c
					srcs/shell/parse_input.c srcs/shell/init_functions.c srcs/shell/destroy_functions.c srcs/shell/init_function_args.c srcs/shell/destroy_function_args.c)

set(READLINE_SRC 	srcs/readline/readline.c
					srcs/readline/array.c
					srcs/readline/check_next_symbol.c
					srcs/readline/term.c
					srcs/readline/prompt.c
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
					srcs/readline/get_next_symbol.c
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
					srcs/readline/get_lines_info.c
					srcs/readline/autocomplete_file_dir.c
					srcs/readline/matrix_init.c
					srcs/readline/line_init.c
					srcs/readline/line_free.c
					srcs/readline/matrix_free.c
					srcs/readline/history_free.c
					srcs/readline/line_del.c
					srcs/readline/matrix_del.c
					srcs/readline/history_del.c
					srcs/readline/matrix_dup.c
					srcs/readline/line_dup.c
					srcs/readline/matrix_cmp.c
					srcs/readline/history_move.c
					srcs/readline/history_move.c
					srcs/readline/cursor_free.c
					srcs/readline/cursor_init.c
					srcs/readline/cursor_dup.c
					srcs/readline/string_init.c
					srcs/readline/string_free.c
					srcs/readline/string_dup.c
					srcs/readline/get_cursor_pos_1.c
					srcs/readline/get_cursor_pos_2.c
					srcs/readline/get_cursor_pos_3.c
					srcs/readline/move_cursor_3.c
					srcs/readline/vi_mode.c
					srcs/readline/readline_buffer.c
					srcs/readline/add_shortcut.c
					srcs/readline/check_modes.c
					srcs/readline/normal_mode.c
					srcs/readline/insert_mode.c
					srcs/readline/replace_mode.c
					srcs/readline/paste_text.c
					srcs/readline/del_text_1.c
					srcs/readline/del_text_2.c
					srcs/readline/yank_text_1.c
					srcs/readline/yank_text_2.c
					srcs/readline/are_default_shortcuts.c
					srcs/readline/matrix_string_yank.c)

set(LEXER_SRC		srcs/lexer/lexer.c
					srcs/lexer/lexer_tools.c)

set(PARSER_SRC		srcs/parser/arith_command.c
					srcs/parser/arith_for_command.c
					srcs/parser/case_clause.c
					srcs/parser/case_clause_sequence.c
					srcs/parser/case_command.c
					srcs/parser/check_words.c
					srcs/parser/check_words_2.c
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

set(EXECUTE_SRC		srcs/execute/errors.c
					srcs/execute/execute.c
					srcs/execute/execlist1.c
					srcs/execute/execlist2.c
					srcs/execute/execlist3.c
					srcs/execute/execpipecmd.c
					srcs/execute/execpipes.c
					srcs/execute/execcmd.c
					srcs/execute/execshellcmd.c
					srcs/execute/execfunction.c
					srcs/execute/execfor.c
					srcs/execute/execcase.c
					srcs/execute/execuntilwhile.c
					srcs/execute/execif.c
					srcs/execute/execsubshell.c
					srcs/execute/execscmd.c
					srcs/execute/initcmd.c
					srcs/execute/getredir.c
					srcs/execute/function.c
					srcs/execute/process.c)

set(BUILTIN_SRC		srcs/builtins/built_cd.c
					srcs/builtins/built_echo.c
					srcs/builtins/built_env.c
					srcs/builtins/built_setenv.c
					srcs/builtins/built_unsetenv.c
					srcs/builtins/built_exit.c
					srcs/builtins/built_echo_reqmts.c srcs/builtins/built_set.c)

set(EXPAND_SRC		srcs/extention/configurate_of_exptention.c
					srcs/extention/configure_remalloc.c
					srcs/extention/extention.c
					srcs/extention/get_true_format.c
					srcs/extention/strins_sheets.c
					srcs/extention/psevdo_functions.c
					srcs/extention/strsplit_for_extention.c
					srcs/extention/stars.c)

include_directories(${INC})
include_directories(${PARSER_INC})
include_directories(${LIBFT_INC})
include_directories(${LIBHASH_INC})
include_directories(${VECTOR_INC})

add_subdirectory(${LIBFT_DIR})
add_subdirectory(${LIBHASH_DIR})
add_subdirectory(${VECTOR_DIR})
add_subdirectory(${LIBSHELL_DIR})

add_executable(${NAME} ${MAIN} ${SHELL_SRC} ${LIBSHELL_SRC} ${BUILTIN_SRC} ${READLINE_SRC} ${LEXER_SRC} ${PARSER_SRC} ${EXECUTE_SRC} ${EXPAND_SRC})
target_link_libraries(${NAME} ${LIBFT} ${LIBHASH} ${VECTOR} ${LIBSHELL})
