#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	while(write(1, ".", 1) != -1)
		sleep(1);
}
