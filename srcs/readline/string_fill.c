#include "readline.h"
#include "libft.h"

void	string_fill(t_string *str, char *buf, int len)
{
	str->buf = (char *)xmalloc(sizeof(char) * len);
	str->len = len;
	ft_memcpy(str->buf, buf, len);
}
