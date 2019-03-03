#include "readline.h"
#include "libshell.h"

t_string	*string_dup(t_string *src)
{
	t_string	*dest;

	if (src == NULL)
		return (NULL);
	dest = (t_string *)xmalloc(sizeof(t_string));
	if (src->buf)
	{
		dest->len = src->len;
		dest->buf = (char *)xmalloc(sizeof(char) * (src->len + 1));
		ft_memcpy(dest->buf, src->buf, src->len);
	}
	else
	{
		dest->len = 0;
		dest->buf = NULL;
	}
	return (dest);
}
