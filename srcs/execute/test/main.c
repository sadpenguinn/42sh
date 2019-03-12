#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

pid_t	pid;
int is_stop;

int forkmain(void)
{
	return (execve("./test", 0, 0));
}

void	handle(int sig)
{
	(void)sig;
	if (is_stop == 0)
	{
		is_stop = 1;
		kill(pid, SIGSTOP);
		printf("\n<<<<<<<<<\nSTOP\n<<<<<<<<<\n");
	}
	else
	{
		is_stop = 0;
		printf("\n>>>>>>>>>\nCONT\n>>>>>>>>>\n");
		kill(pid, SIGCONT);
		waitpid(pid, 0, 0);
	}
}

int main(void)
{
	struct sigaction	action;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGTSTP);
	sigaddset(&set, SIGCONT);
	memset(&action, 0, sizeof(action));
	action.sa_handler = handle;
	action.sa_mask = set;
	sigaction(SIGTSTP, &action, 0);
	sigaction(SIGCONT, &action, 0);

	if (!(pid = fork()))
		return (forkmain());
	waitpid(pid, 0, 0);
	printf("PID RETURNED\n");
	while (1);
}
