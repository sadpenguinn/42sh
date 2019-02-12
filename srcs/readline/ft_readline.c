#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "readline.h"
#include <unistd.h>
#include <termios.h>

int len;

static void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

void    clear_screen_down(void)
{
	ft_puts(CSI "0J", 0);
}

static void    print_prompt(void)
{
/*	ft_puts(CSI "4A", 0);*/
	clear_screen_down();
/*	ft_puts(PROMPT_COLOR "prompt" "\n", 0);*/
	ft_puts("prompt", 0);
}

int     check_next_symbol(char *buf)
{
	t_uchar c;

	c = get_next_symbol();
	if (c == '\n')
		return (0);
	buf[len++] = c;
	return (1);
}

int     ft_readline(void)
{
	int     ret;
	char    c;
	char    buf[100];
	ft_memset(buf, 0, 100);
	len = 0;
	struct termios  old;
	struct termios	new;

	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);
	read(0, &c, 1);
	ft_puts(CURSOR_CLEAR_SCREEN, 0);
//	ft_puts(CSI "2K", 0)
	read(0, &c, 1);
	print_prompt();
	read(0, &c, 1);
	ft_puts(CSI "1A", 0);
	ft_puts(CSI "1G", 0);
	tcsetattr(0, TCSANOW, &old);
	while ((ret = check_next_symbol(buf)))
		;
	if (strcmp(buf, "exit") == 0)
		return (0);
	return (1);
}