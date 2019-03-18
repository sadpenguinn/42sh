#include "builtins.h"

int	built_fc_case_l(char **av, int i, int *flags, void **fc_history)
{
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
	write_lines(fc_history, 0, flags, av + i);
}