#include <unistd.h>
#include <signal.h>

int main(void)
{
	kill(-1, SIGSTOP);
}

