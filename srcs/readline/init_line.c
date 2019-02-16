#include "readline.h"
#include "shell.h"

t_line *init_line(void)
{
	t_line *line;

	line = (t_line *)xmalloc(sizeof(t_line));
	line->buf = (char *)xmalloc(sizeof(char) * BUF_DEFAULT + 1);
	line->size = BUF_DEFAULT;
	line->len = 0;
	line->symbols = 0;
	return (line);
}
