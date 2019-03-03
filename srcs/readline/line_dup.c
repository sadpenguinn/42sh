#include "readline.h"
#include "libshell.h"

t_line	*line_dup(t_line *src)
{
	t_line	*dest;

	dest = (t_line *)xmalloc(sizeof(t_line));
	dest->size = src->size;
	dest->buf = (char *)xmalloc(sizeof(char) * (dest->size + 1));
	dest->len = src->len;
	dest->symbols = src->symbols;
	ft_strcpy(dest->buf, src->buf);
	return (dest);
}
