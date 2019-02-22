SRC = ../lib/libft/srcs/xmalloc.c\
	  ../lib/libft/srcs/xrealloc.c\
	  ../lib/libft/srcs/ft_memset.c\
	  ../lib/libft/srcs/ft_strnum.c\
	  ../lib/libft/srcs/ft_strnum_base.c\
	  readline.c main.c array.c\
	  check_next_symbol.c term.c prompt.c\
	  init_matrix.c init_line.c resize_windows.c\
	  matrix_resize.c line_resize.c\
	  move_cursor_1.c move_cursor_2.c\
	  check_esc_code.c matrix_string_insert.c\
	  matrix_create_line.c utf.c matrix_string_delete.c\
	  buttons1.c matrix_erase_line.c readline_memdel.c\

NAME = line
TEST = a.test

all:
	gcc -Wall -Wextra -Werror $(SRC) -I ../../includes -I ../lib/vector/includes -I . -I ../lib/libft/includes -I ../lib/libhash/includes -o $(NAME)

clean:
	rm -rf $(NAME) $(NAME).dSYM a.out a.out.dSYM $(TEST)

test:
	gcc term.c test.c -o $(TEST)
