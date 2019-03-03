#include "readline.h"
#include <stdlib.h>

void	string_free(t_string *str)
{
	if (str == NULL)
		return ;
	free(str->buf);
	free(str);
}
