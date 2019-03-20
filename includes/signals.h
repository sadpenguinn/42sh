#ifndef SIGNALS_H
# define SIGNALS_H

extern void		(*g_sigchld)(int);

void			handle_sigchld(int sig);
void			freepids(void **pids);

#endif
