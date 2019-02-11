cmake_minimum_required(VERSION 3.13)
project(42sh)

set(NAME 42sh)
set(INC includes)
set(PARSER_INC srcs/parser)
set(LIBFT_INC srcs/lib/libft/includes)
set(LIBHASH_INC srcs/lib/libhash/includes)
set(VECTOR_INC srcs/lib/vector/includes)

set(LEXER_SRC   srcs/lexer/lexer.c
                srcs/lexer/lexer_tools.c)

set(LIBFT_SRC   srcs/lib/libft/srcs/fatal_error.c
                srcs/lib/libft/srcs/ft_atoi.c
srcs/lib/libft/srcs/ft_btree_count.c
srcs/lib/libft/srcs/ft_btree_del.c
srcs/lib/libft/srcs/ft_btree_infix.c
srcs/lib/libft/srcs/ft_btree_ins.c
srcs/lib/libft/srcs/ft_btree_new.c
srcs/lib/libft/srcs/ft_btree_prefix.c
srcs/lib/libft/srcs/ft_btree_search.c
srcs/lib/libft/srcs/ft_btree_sort.c
srcs/lib/libft/srcs/ft_btree_suffix.c
srcs/lib/libft/srcs/ft_bzero.c
srcs/lib/libft/srcs/ft_charsize.c
srcs/lib/libft/srcs/ft_err_msg.c
srcs/lib/libft/srcs/ft_isalnum.c
srcs/lib/libft/srcs/ft_isalpha.c
srcs/lib/libft/srcs/ft_isascii.c
srcs/lib/libft/srcs/ft_isblank.c
srcs/lib/libft/srcs/ft_iscntrl.c
srcs/lib/libft/srcs/ft_isdigit.c
srcs/lib/libft/srcs/ft_isgraph.c
srcs/lib/libft/srcs/ft_islower.c
srcs/lib/libft/srcs/ft_isprint.c
srcs/lib/libft/srcs/ft_isspace.c
srcs/lib/libft/srcs/ft_isupper.c
srcs/lib/libft/srcs/ft_isxdigit.c
srcs/lib/libft/srcs/ft_itoa.c
srcs/lib/libft/srcs/ft_itoa_base.c
srcs/lib/libft/srcs/ft_listlast.c
srcs/lib/libft/srcs/ft_listnew.c
srcs/lib/libft/srcs/ft_memalloc.c
srcs/lib/libft/srcs/ft_memccpy.c
srcs/lib/libft/srcs/ft_memchr.c
srcs/lib/libft/srcs/ft_memcmp.c
srcs/lib/libft/srcs/ft_memcpy.c
srcs/lib/libft/srcs/ft_memdel.c
srcs/lib/libft/srcs/ft_memdup.c
srcs/lib/libft/srcs/ft_memmove.c
srcs/lib/libft/srcs/ft_memset.c
srcs/lib/libft/srcs/ft_numlen.c
srcs/lib/libft/srcs/ft_pathadd.c
srcs/lib/libft/srcs/ft_pop.c
srcs/lib/libft/srcs/ft_pow.c
srcs/lib/libft/srcs/ft_push.c
srcs/lib/libft/srcs/ft_push_back.c
srcs/lib/libft/srcs/ft_putchar.c
srcs/lib/libft/srcs/ft_putchar_fd.c
srcs/lib/libft/srcs/ft_putendl.c
srcs/lib/libft/srcs/ft_putendl_fd.c
srcs/lib/libft/srcs/ft_putnbr.c
srcs/lib/libft/srcs/ft_putnbr_fd.c
srcs/lib/libft/srcs/ft_putnbrendl.c
srcs/lib/libft/srcs/ft_putnchr.c
srcs/lib/libft/srcs/ft_putstr.c
srcs/lib/libft/srcs/ft_putstr_fd.c
srcs/lib/libft/srcs/ft_str_is_alpha.c
srcs/lib/libft/srcs/ft_str_is_lowercase.c
srcs/lib/libft/srcs/ft_str_is_number.c
srcs/lib/libft/srcs/ft_str_is_numeric.c
srcs/lib/libft/srcs/ft_str_is_printable.c
srcs/lib/libft/srcs/ft_str_is_uppercase.c
srcs/lib/libft/srcs/ft_stradd.c
srcs/lib/libft/srcs/ft_strcat.c
srcs/lib/libft/srcs/ft_strchr.c
srcs/lib/libft/srcs/ft_strclr.c
srcs/lib/libft/srcs/ft_strcmp.c
srcs/lib/libft/srcs/ft_strcolor.c
srcs/lib/libft/srcs/ft_strcpy.c
srcs/lib/libft/srcs/ft_strdel.c
srcs/lib/libft/srcs/ft_strdup.c
srcs/lib/libft/srcs/ft_strequ.c
srcs/lib/libft/srcs/ft_striter.c
srcs/lib/libft/srcs/ft_striteri.c
srcs/lib/libft/srcs/ft_strjoin.c
srcs/lib/libft/srcs/ft_strlcat.c
srcs/lib/libft/srcs/ft_strlen.c
srcs/lib/libft/srcs/ft_strlowcase.c
srcs/lib/libft/srcs/ft_strmap.c
srcs/lib/libft/srcs/ft_strmapi.c
srcs/lib/libft/srcs/ft_strncat.c
srcs/lib/libft/srcs/ft_strncmp.c
srcs/lib/libft/srcs/ft_strncpy.c
srcs/lib/libft/srcs/ft_strndup.c
srcs/lib/libft/srcs/ft_strnequ.c
srcs/lib/libft/srcs/ft_strnew.c
srcs/lib/libft/srcs/ft_strnstr.c
srcs/lib/libft/srcs/ft_strnum.c
srcs/lib/libft/srcs/ft_strnum_base.c
srcs/lib/libft/srcs/ft_strrchr.c
srcs/lib/libft/srcs/ft_strrev.c
srcs/lib/libft/srcs/ft_strsplit.c
srcs/lib/libft/srcs/ft_strstr.c
srcs/lib/libft/srcs/ft_strsub.c
srcs/lib/libft/srcs/ft_strtrim.c
srcs/lib/libft/srcs/ft_strupcase.c
srcs/lib/libft/srcs/ft_tolower.c
srcs/lib/libft/srcs/ft_toupper.c
srcs/lib/libft/srcs/get_next_line.c)

set(LIBHASH_SRC srcs/lib/libhash/srcs/hash_clean.c
        srcs/lib/libhash/srcs/hash_delete.c
        srcs/lib/libhash/srcs/hash_find.c
        srcs/lib/libhash/srcs/hash_foreach.c
        srcs/lib/libhash/srcs/hash_index.c
        srcs/lib/libhash/srcs/hash_init.c
        srcs/lib/libhash/srcs/hash_insert.c
        srcs/lib/libhash/srcs/hash_print.c
        srcs/lib/libhash/srcs/hash_test.c)

set(LIBSHELL_SRC        srcs/lib/libshell/check_varname.c
srcs/lib/libshell/glob.c
srcs/lib/libshell/match.c
srcs/lib/libshell/xmalloc.c
srcs/lib/libshell/xrealloc.c
srcs/lib/libshell/die.c)

set(LIBVECTOR_SRC       srcs/lib/vector/srcs/ft_ceill.c
srcs/lib/vector/srcs/ft_floorl.c
srcs/lib/vector/srcs/queue_back.c
srcs/lib/vector/srcs/queue_create.c
srcs/lib/vector/srcs/queue_free.c
srcs/lib/vector/srcs/queue_front.c
srcs/lib/vector/srcs/queue_pop_back.c
srcs/lib/vector/srcs/queue_push_back.c
srcs/lib/vector/srcs/vector_back.c
srcs/lib/vector/srcs/vector_create.c
srcs/lib/vector/srcs/vector_foreach.c
srcs/lib/vector/srcs/vector_free.c
srcs/lib/vector/srcs/vector_front.c
srcs/lib/vector/srcs/vector_get_elem.c
srcs/lib/vector/srcs/vector_get_len.c
srcs/lib/vector/srcs/vector_is_empty.c
srcs/lib/vector/srcs/vector_pop_back.c
srcs/lib/vector/srcs/vector_push_back.c
srcs/lib/vector/srcs/vector_to_array.c)

set(PARSER_SRC srcs/parser/arith_command.c
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

set(MAIN srcs/shell.c)

include_directories(${INC})
include_directories(${PARSER_INC})
include_directories(${LIBFT_INC})
include_directories(${LIBHASH_INC})
include_directories(${VECTOR_INC})

add_executable(42sh ${MAIN} ${LEXER_SRC} ${LIBFT_SRC} ${LIBHASH_SRC} ${LIBSHELL_SRC} ${LIBVECTOR_SRC} ${PARSER_SRC})
