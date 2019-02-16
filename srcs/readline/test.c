#include <stdio.h>
#include <unistd.h>
#include "term.h"
#include <fcntl.h>

int main(void)
{
	unsigned char c = 0;
	set_term();
		read(0, &c, 1);
	while (c != '\n')
	{
		printf("%d\n", c);
		read(0, &c, 1);
	}
	unset_term();
	return (0);
}
