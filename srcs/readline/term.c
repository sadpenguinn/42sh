#include <term.h>

static struct termios g_old;

void    set_term(void)
{
	struct termios	new;

	tcgetattr(0, &g_old);
	new = g_old;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VLNEXT] = 022;
	new.c_cc[VEOF] = 04;
	new.c_cc[VREPRINT] = 022;
	new.c_cc[VQUIT] = 034;
	tcsetattr(0, TCSANOW, &new);
}

void    unset_term(void)
{
	tcsetattr(0, TCSANOW, &g_old);
}
