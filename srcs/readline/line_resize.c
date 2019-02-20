#include "readline.h"
#include "shell.h"

void    line_resize(t_line *line, int new_size, int old_size)
{
	line->buf = (char *)xrealloc(line->buf, new_size + 1, old_size);
	line->size = new_size;
}
