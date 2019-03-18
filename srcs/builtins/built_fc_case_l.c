#include "builtins.h"

int	built_fc_case_l(char **av, int i, int *flags, void *fc_history)
{
	built_fc_write_lines(fc_history, 1, flags, av + i);
	return (1);
}