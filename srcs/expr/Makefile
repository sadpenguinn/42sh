all:
	gcc *.c */*.c ../lexer/lexer_tools.c ../lib/libft/libft.a ../lib/libshell/libshell.a ../lib/libhash/libhash.a ../lib/vector/libvector.a -I ../../includes -I ../lib/libft/includes -I ../lib/libhash/includes -I ../lib/vector/includes -I .

clean:
	rm -rf a.out

fclean: clean

re: fclean all