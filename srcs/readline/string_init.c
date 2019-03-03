#include "readline.h"
#include "shell.h"

t_string	*string_init(void)
{
	t_string	*str;

	str = (t_string *)xmalloc(sizeof(t_string));
	str->len = 0;
	str->buf = NULL;
	return (str);
}
