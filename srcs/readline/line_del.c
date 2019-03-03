#include "readline.h"
#include <stdlib.h>

void	line_del(t_line **line)
{
	if (line == NULL)
		return ;
	line_free(*line);
	*line = NULL;
}
