#include <stdlib.h>
#include "readline.h"
#include "term.h"
#include "shell.h"

int		main(void)
{
	char *str;

	while ((str = readline()))
	{
		write(1, str, strlen(str));
	}
	return (0);
}
