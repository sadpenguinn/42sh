SRC = \
../lib/libshell/xmalloc.c\
../lib/libshell/xrealloc.c\
../lib/libft/srcs/ft_memset.c\
readline.c main.c array.c\
check_next_symbol.c term.c prompt.c\
init_matrix.c init_line.c is_utf.c\

NAME = line

all:
	gcc -Wall -Wextra -Werror $(SRC) -I ../../includes -I . -I ../lib/libft/includes -I ../lib/libhash/includes -o $(NAME)

clean:
	rm -rf $(NAME) $(NAME).dSYM a.out a.out.dSYM

test:
	gcc term.c test.c -o a.test
