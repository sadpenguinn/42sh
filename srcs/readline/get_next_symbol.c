#include "readline.h"
#include <unistd.h>

t_uchar		get_next_symbol(size_t size)
{
	t_uchar	c;

	c = 0;
	if (size > sizeof(t_uchar))
		size = sizeof(t_uchar);
	read(0, &c, size);
	return (c);
}
