#include "readline.h"
#include "shell.h"

t_cursor	*cursor_init(void)
{
	t_cursor	*cursor;
	cursor = (t_cursor *)xmalloc(sizeof(t_cursor));
	cursor->row = 0;
	cursor->col = 0;
	return (cursor);
}
