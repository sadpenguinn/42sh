#include "calc.h"

extern int		g_exprerr;

intmax_t	calcerror(int err)
{
	g_exprerr = 1;
	(void)err;
	return (0);
}
