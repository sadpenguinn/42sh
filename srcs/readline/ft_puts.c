#include <unistd.h>
#include <string.h>

void	ft_puts(char *buf)
{
	int	len;

	len = strlen(buf);
	write(1, buf, len);
}

