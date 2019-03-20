#ifndef SIGNALS_H
# define SIGNALS_H

void			handle_sigchld(int sig);

extern void		(*g_sigchld)(int);

#endif
