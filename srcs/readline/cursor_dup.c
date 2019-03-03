#include "readline.h"
#include "libshell.h"

t_cursor	*cursor_dup(t_cursor *src)
{
	t_cursor	*dest;

	if (src == NULL)
		return (NULL);
	dest = (t_cursor *)xmalloc(sizeof(t_cursor));
	dest->row = src->row;
	dest->col = src->col;
	return (dest);
}
