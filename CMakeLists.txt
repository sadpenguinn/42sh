cmake_minimum_required(VERSION 3.13)
project(42sh)

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

set(MAIN			srcs/shell.c)

set(LEXER_SRC		srcs/lexer/lexer.c
					srcs/lexer/lexer_tools.c)

set(LIBSHELL_SRC	srcs/lib/libshell/check_varname.c
					srcs/lib/libshell/glob.c
					srcs/lib/libshell/match.c
					srcs/lib/libshell/xmalloc.c
					srcs/lib/libshell/xrealloc.c
					srcs/lib/libshell/die.c)

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
					srcs/parser/io_file.c
					srcs/parser/io_here.c
					srcs/parser/list0.c
					srcs/parser/list1.c
					srcs/parser/list2.c
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

add_executable(42sh ${MAIN} ${LEXER_SRC} ${PARSER_SRC} ${LIBSHELL_SRC})
target_link_libraries(42sh ${LIBFT} ${LIBHASH} ${VECTOR})
