cmake_minimum_required(VERSION 3.13)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In source builds not allowed. Please make a new directory" )
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
set(LIBALIAS		alias)
set(LIBALIAS_DIR	srcs/lib/libalias)
set(LIBALIAS_INC	srcs/lib/libalias/includes)
set(VECTOR			vector)
set(VECTOR_DIR		srcs/lib/vector)
set(VECTOR_INC		srcs/lib/vector/includes)
set(LIBSHELL		shell)
set(LIBSHELL_DIR	srcs/lib/libshell)
set(MATH_LIB		m)

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
					srcs/shell/init_jobs.c
					srcs/shell/destroy_jobs.c
					srcs/shell/signals.c
					srcs/shell/sigchld.c
					srcs/shell/argv_parser.c
					srcs/shell/parse_input.c
					srcs/shell/init_functions.c
					srcs/shell/destroy_functions.c
					srcs/shell/init_function_args.c
					srcs/shell/destroy_function_args.c
					srcs/shell/init_aliases.c
					srcs/shell/substitution.c
					srcs/shell/destroy_aliases.c
					srcs/lib/libshell/srcs/check_varname.c)

set(CONDITIONS_SRC	srcs/conditions/b_to_g_conditions.c
					srcs/conditions/cond_flags_switcher.c
					srcs/conditions/cond_print_errors.c
					srcs/conditions/cond_string_sheets.c
					srcs/conditions/conditions.c
					srcs/conditions/l_to_s_conditions.c
					srcs/conditions/num_conditions.c
					srcs/conditions/strings_conditions.c
					srcs/conditions/u_to_x_conditions.c)

set(AUTOCOMPLI_SRC	srcs/autocomplete/autocomplete.c
					srcs/autocomplete/autocomplite_builtins.c
					srcs/autocomplete/autocomplite_env.c
					srcs/autocomplete/autocomplite_files_and_dirs.c
					srcs/autocomplete/autocomplite_functions.c
					srcs/autocomplete/autocomplite_in_hash.c
					srcs/autocomplete/autocomplite_lib.c
					srcs/autocomplete/autocomplite_specific_cases.c
					srcs/autocomplete/post_procession.c
					srcs/autocomplete/pre_procession.c
					srcs/autocomplete/autocomplete_flags.c
					srcs/autocomplete/beautifylizing_flags_output.c
					srcs/autocomplete/autocomplete_backslashing.c
					srcs/autocomplete/autocomplete_other.c
					srcs/autocomplete/autocomplete_get_type.c
					srcs/autocomplete/clever_autocomplete_checks.c
					srcs/autocomplete/autocomplete_files_or_dirs.c
					srcs/autocomplete/processing_hidden_files.c)

set(READLINE_SRC 	srcs/readline/readline.c
					srcs/readline/heredoc.c
					srcs/readline/history_save.c
					srcs/readline/history_fill.c
					srcs/readline/history_resize.c
					srcs/readline/array.c
					srcs/readline/check_next_symbol.c
					srcs/readline/term.c
					srcs/readline/prompt.c
					srcs/readline/resize_windows.c
					srcs/readline/matrix_resize.c
					srcs/readline/line_resize.c
					srcs/readline/check_esc_code.c
					srcs/readline/matrix_string_insert.c
					srcs/readline/matrix_string_delete.c
					srcs/readline/matrix_string_yank.c
					srcs/readline/matrix_insert_line.c
					srcs/readline/utf.c
					srcs/readline/back_space_symbol.c
					srcs/readline/del_symbol.c
					srcs/readline/matrix_erase_line.c
					srcs/readline/get_next_symbol.c
					srcs/readline/newline_handling.c
					srcs/readline/add_style.c
					srcs/readline/add_text.c
					srcs/readline/add_words.c
					srcs/readline/symbol_to_string.c
					srcs/readline/set_matrix_limits.c
					srcs/readline/matrix_to_string.c
					srcs/readline/count_string_objects.c
					srcs/readline/print_1.c
					srcs/readline/print_2.c
					srcs/readline/readline_mode.c
					srcs/readline/search_mode.c
					srcs/readline/add_cursor_offset.c
					srcs/readline/reset_last_offset.c
					srcs/readline/add_line_prefix.c
					srcs/readline/get_lines_info.c
					srcs/readline/matrix_init.c
					srcs/readline/modification_init.c
					srcs/readline/modification_resize.c
					srcs/readline/modification_free.c
					srcs/readline/action_add.c
					srcs/readline/action_free.c
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
					srcs/readline/cursor_free.c
					srcs/readline/cursor_init.c
					srcs/readline/cursor_dup.c
					srcs/readline/string_init.c
					srcs/readline/string_free.c
					srcs/readline/string_del.c
					srcs/readline/string_dup.c
					srcs/readline/string_fill.c
					srcs/readline/get_cursor_pos_1.c
					srcs/readline/get_cursor_pos_2.c
					srcs/readline/get_cursor_pos_3.c
					srcs/readline/get_space_pos.c
					srcs/readline/move_cursor_1.c
					srcs/readline/move_cursor_2.c
					srcs/readline/move_cursor_3.c
					srcs/readline/move_cursor_4.c
					srcs/readline/vi_mode.c
					srcs/readline/readline_buffer.c
					srcs/readline/add_shortcut.c
					srcs/readline/modes_handling.c
					srcs/readline/vi_mode_normal.c
					srcs/readline/are_default_vi_normal_mode_shortcuts.c
					srcs/readline/vi_mode_normal_del.c
					srcs/readline/vi_mode_normal_yank.c
					srcs/readline/vi_mode_insert.c
					srcs/readline/vi_mode_replace.c
					srcs/readline/vi_mode_visual.c
					srcs/readline/vi_mode_visual_is_normal_mode.c
					srcs/readline/paste_text.c
					srcs/readline/del_text_1.c
					srcs/readline/del_text_2.c
					srcs/readline/del_text_3.c
					srcs/readline/yank_text_1.c
					srcs/readline/yank_text_2.c
					srcs/readline/yank_text_3.c
					srcs/readline/lex_check_bash_word.c
					srcs/readline/are_quotes.c
					srcs/readline/bang_handling.c
					srcs/readline/bang_cases.c
					srcs/readline/set_backslash.c
					srcs/readline/undo.c
					srcs/readline/redo.c
					srcs/readline/check_cursor_swap.c)

set(LEXER_SRC		srcs/lexer/lexer.c
					srcs/lexer/lexer_tools.c
					srcs/lexer/dfa_tools.c)

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
					srcs/parser/pattern.c
					srcs/parser/pattern_list.c
					srcs/parser/pipeline.c
					srcs/parser/pipeline_command.c
					srcs/parser/print_astree.c
					srcs/parser/redirection.c
					srcs/parser/redirection_list.c
					srcs/parser/select_command.c
					srcs/parser/shell_command.c
					srcs/parser/simple_command.c
					srcs/parser/simple_command_element.c
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
					srcs/execute/process.c
					srcs/execute/job.c
					srcs/execute/alias.c)

set(BUILTIN_SRC		srcs/builtins/built_cd.c
					srcs/builtins/built_echo.c
					srcs/builtins/built_env.c
					srcs/builtins/built_setenv.c
					srcs/builtins/built_unsetenv.c
					srcs/builtins/built_exit.c
					srcs/builtins/built_echo_reqmts.c
					srcs/builtins/built_set.c
					srcs/builtins/built_fc.c
					srcs/builtins/built_fc_reqmts.c
					srcs/builtins/built_fc_write_lines.c
					srcs/builtins/built_fc_case_default.c
					srcs/builtins/built_fc_case_e.c
					srcs/builtins/built_fc_case_l.c
					srcs/builtins/built_fc_case_s.c
					srcs/builtins/built_hash.c
					srcs/builtins/built_export.c
					srcs/builtins/built_hash_reqmts.c
					srcs/builtins/built_set_rqmts.c
					srcs/builtins/built_jobs.c
					srcs/builtins/built_bg.c
					srcs/builtins/built_fg.c
					srcs/builtins/built_alias.c
					srcs/builtins/built_unalias.c srcs/builtins/built_type.c srcs/builtins/built_test.c)

set(EXPAND_SRC		srcs/extention/configurate_of_exptention.c
					srcs/extention/configure_remalloc.c
					srcs/extention/extention.c
					srcs/extention/get_true_format.c
					srcs/extention/norma_fucking_sheet.c
					srcs/extention/psevdo_functions.c
					srcs/extention/remove_suffix_prefix_patterns.c
					srcs/extention/spec_cases.c
					srcs/extention/stars.c
					srcs/extention/strins_sheets.c
					srcs/extention/strsplit_for_extention.c
					srcs/extention/pre_processings.c
					srcs/extention/get_fd_of_redirs.c
					srcs/extention/arithm_extention.c)

set(EXPR			srcs/expr/expression.c)

set(EXPR_LEXER		srcs/expr/exprlexer/exprlexer.c)

set(EXPR_PARSER		srcs/expr/exprparser/expr.c
					srcs/expr/exprparser/expr1.c
					srcs/expr/exprparser/expr2.c
					srcs/expr/exprparser/expr3.c
					srcs/expr/exprparser/expr4.c
					srcs/expr/exprparser/expr5.c
					srcs/expr/exprparser/expr6.c
					srcs/expr/exprparser/expr7.c
					srcs/expr/exprparser/expr8.c
					srcs/expr/exprparser/expr9.c
					srcs/expr/exprparser/expr10.c
					srcs/expr/exprparser/expr11.c
					srcs/expr/exprparser/expr12.c
					srcs/expr/exprparser/expr13.c
					srcs/expr/exprparser/expr14.c
					srcs/expr/exprparser/operand.c
					srcs/expr/exprparser/otherfunc.c
					srcs/expr/exprparser/postincdec.c
					srcs/expr/exprparser/preincdec.c
					srcs/expr/exprparser/preunary.c
					srcs/expr/exprparser/variable.c
					)

set(EXPR_CALC		srcs/expr/exprcalc/calc.c
					srcs/expr/exprcalc/bits_operators.c
					srcs/expr/exprcalc/calcarray.c
					srcs/expr/exprcalc/calcerror.c
					srcs/expr/exprcalc/logical_operators.c
					srcs/expr/exprcalc/math_operators.c
					srcs/expr/exprcalc/variable.c
					)

include_directories(${INC})
include_directories(${PARSER_INC})
include_directories(${LIBFT_INC})
include_directories(${LIBHASH_INC})
include_directories(${LIBALIAS_INC})
include_directories(${VECTOR_INC})

add_subdirectory(${LIBFT_DIR})
add_subdirectory(${LIBHASH_DIR})
add_subdirectory(${LIBALIAS_DIR})
add_subdirectory(${VECTOR_DIR})
add_subdirectory(${LIBSHELL_DIR})

add_executable(			${NAME} ${MAIN} ${SHELL_SRC}
						${LIBSHELL_SRC} ${BUILTIN_SRC} ${READLINE_SRC}
						${LEXER_SRC} ${PARSER_SRC} ${EXECUTE_SRC}
						${EXPAND_SRC} ${EXPR} ${EXPR_LEXER} ${EXPR_PARSER}
						${EXPR_CALC} ${AUTOCOMPLI_SRC} ${CONDITIONS_SRC})

target_link_libraries(	${NAME} ${LIBSHELL} ${LIBFT} ${LIBHASH}
						${VECTOR} ${LIBALIAS} ${MATH_LIB})
