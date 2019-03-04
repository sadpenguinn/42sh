SRC = ../lib/libft/srcs/xmalloc.c\
	  ../lib/libft/srcs/xrealloc.c\
	  ../lib/libft/srcs/ft_memset.c\
	  ../lib/libft/srcs/ft_strnum.c\
	  ../lib/libft/srcs/ft_strnum_base.c\
	  ../lib/libft/srcs/ft_strdup.c\
	  ../lib/libft/srcs/ft_strcmp.c\
	  ../lib/libft/srcs/ft_strndup.c\
	  ../lib/libft/srcs/ft_strjoin.c\
	  ../lib/libft/srcs/ft_strlen.c\
	  ../lib/libft/srcs/ft_memcpy.c\
	  ../lib/libft/srcs/ft_memmove.c\
	  ../lib/libft/srcs/ft_strcpy.c\
	  ../lib/libft/srcs/ft_strchr.c\
	  ../lib/libshell/srcs/xglob.c\
	  ../lib/libshell/srcs/xmatch.c\
	  readline.c\
	  main.c\
	  array.c\
	  check_next_symbol.c\
	  term.c prompt.c\
	  matrix_init.c\
	  line_init.c\
	  resize_windows.c\
	  matrix_resize.c\
	  line_resize.c\
	  move_cursor_1.c\
	  move_cursor_2.c\
	  check_esc_code.c\
	  matrix_string_insert.c\
	  matrix_create_line.c\
	  utf.c\
	  matrix_string_delete.c\
	  buttons1.c\
	  matrix_erase_line.c\
	  matrix_free.c\
	  line_free.c\
	  history_free.c\
	  line_del.c\
	  matrix_del.c\
	  history_del.c\
	  get_next_symbol.c\
	  newline_handling.c\
	  add_style.c\
	  add_text.c\
	  symbol_to_string.c\
	  set_matrix_limits.c\
	  matrix_to_string.c\
	  count_string_objects.c\
	  print.c readline_mode.c\
	  add_cursor_offset.c\
	  add_line_prefix.c\
	  get_lines_info.c\
	  autocomplete_file_dir.c\
	  matrix_dup.c\
	  line_dup.c\
	  matrix_cmp.c\
	  history_move.c\
	  cursor_free.c\
	  cursor_init.c\
	  cursor_dup.c\
	  string_init.c\
	  string_free.c\
	  string_dup.c\
	  get_cursor_pos_1.c\
	  get_cursor_pos_2.c\
	  get_cursor_pos_3.c\
	  move_cursor_3.c\
	  vi_mode.c\
	  readline_buffer.c\
	  add_shortcut.c\
	  check_modes.c\
	  normal_mode.c\
	  paste_text.c\
	  del_text_1.c\
	  yank_text_1.c\
	  are_default_shortcuts.c\
	  matrix_string_yank.c\

NAME = line
TEST = a.test

all:
	gcc -Wall -Wextra -Werror $(SRC) -I ../../includes -I ../lib/vector/includes -I . -I ../lib/libft/includes -I ../lib/libhash/includes -o $(NAME)

clean:
	rm -rf $(NAME) $(NAME).dSYM a.out a.out.dSYM $(TEST)

test:
	gcc term.c test.c -I ../../includes  -o $(TEST)
