#include "readline.h"
#include <stdlib.h>

void	cursor_free(t_cursor *cursor)
{
	free(cursor);
}
