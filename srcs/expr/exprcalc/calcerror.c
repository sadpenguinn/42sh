#include "calc.h"

extern int		g_calcerr;

intmax_t	calcerror(int err)
{
	g_calcerr = 1;
	printf("Calc error %d\n", err);
	return (0);
}
