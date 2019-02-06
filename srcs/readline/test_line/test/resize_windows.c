#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

struct winsize	g_w;

void	get_term_params(struct winsize	*w)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, w);
}

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "got\n", 4);
}

void	term_monitoring(pid_t pid)
{
	struct winsize	w;

	while (1)
	{
		get_term_params(&w);
		if (w.ws_row != g_w.ws_row || w.ws_col != g_w.ws_col)
		{
			kill(pid, SIGUSR1);
			g_w.ws_row = w.ws_row;
			g_w.ws_col = w.ws_col;
		}
	}
}

int		main(void)
{
	pid_t	pid;
	get_term_params(&g_w);
	signal(SIGUSR1, sig_handler);
	if ((pid = fork()))
	{
		term_monitoring(pid);
	}
	while(1);
}
