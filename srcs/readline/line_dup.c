#include "readline.h"
#include "libshell.h"

t_line	*line_dup(t_line *src)
{
	t_line	*dest;

	if (src == NULL)
		return (NULL);
	dest = (t_line *)xmalloc(sizeof(t_line));
	if (src->buf)
	{
		dest->size = src->size;
		dest->buf = (char *)xmalloc(sizeof(char) * (dest->size + 1));
		dest->len = src->len;
		dest->symbols = src->symbols;
		ft_memcpy(dest->buf, src->buf, src->len);
	}
	else
	{
		dest->size = 0;
		dest->len = 0;
		dest->symbols = 0;
		dest->buf = NULL;
	}
	return (dest);
}
