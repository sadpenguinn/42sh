#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "readline.h"
#include <unistd.h>
#include "term.h"

int len;

void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

int     check_next_symbol(char *buf)
{
	t_uchar c;

	c = get_next_symbol();
	if (c == '\n')
	{
		if (len != 0)
			write(1, &c, sizeof(t_uchar));
		return (0);
	}
	write(1, &c, sizeof(t_uchar));
	buf[len++] = c;
	return (1);
}

int     ft_readline(void)
{
	int     ret;
//	char    c;
	char    buf[100];
	ft_memset(buf, 0, 100);
	len = 0;

	set_term();
	print_prompt();
	while ((ret = check_next_symbol(buf)))
		;
	unset_term();
	if (strcmp(buf, "exit") == 0)
		return (0);
	return (1);
}