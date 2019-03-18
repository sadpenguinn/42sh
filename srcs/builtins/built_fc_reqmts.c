#include "builtins.h"
#include "readline.h"

int	built_fc_usage(void)
{
	array_add("fc usage: \n", ft_strlen("fc usage: \n"));
	array_flush();
	return (0);
}

