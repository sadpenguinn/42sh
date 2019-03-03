#include "readline.h"
#include <stdlib.h>

void	line_free(t_line *line)
{
	if (line == NULL)
		return ;
	free(line->buf);
	free(line);
}
