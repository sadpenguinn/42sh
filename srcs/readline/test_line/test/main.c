#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <termios.h>

#define CSI "\e["
#define COLOR_TEXT "\e[0m\e[1;32;49m"
#define COLOR_KEYWORDS "\e[0m\e[1;33;49m"
#define TERM_DEFAULT "\e[0m"
#define COLOR_PROMPT "\e[0m\e[34;49m"
#define COLOR_INVERT "\e[7m"
#define CURSOR_SAVE "\e[s"
#define CURSOR_RESTORE "\e[u"

void	ft_put(char *str)
{
	int		len;

	len = strlen(str);
	write(1, str, len);
}

int		main(void)
{
	struct termios	old;
	struct termios	new;
	char	c;
	int		i;
	int		j;

	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);
	ft_put(CURSOR_SAVE);
	/* write(1, CSI "?25l", 6); */
	/* read(1, &c, 1); */
	i = 0;
	j = 0;
	while (++j <= 3)
	{
		ft_put(COLOR_TEXT);
		while (++i <= 3000)
			ft_put("abcde");
		int a = 0;
		while (++a <= j)
			ft_put(CSI "1D");
		read(1, &c, 1);
		ft_put(CURSOR_RESTORE);
	}
	/* write(1, CSI "?25l", 6); */
}
