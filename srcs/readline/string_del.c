#include "readline.h"
#include <stdlib.h>

void	string_del(t_string **str)
{
	if (str == NULL)
		return ;
	string_free(*str);
	*str = NULL;
}
