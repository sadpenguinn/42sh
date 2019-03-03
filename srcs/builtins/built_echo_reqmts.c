#include "builtins.h"

static int 	hex_sequence(const char *str, int i)
{
	char 	stack[4];
	int 	k;

	i++;
	k = 0;
	while (ft_isxdigit(str[i]) && k < 2)
	{
		stack[k] = str[i];
		k++;
		i++;
	}
	stack[k] = '\0';
	ft_putchar(ft_atoi_base(stack, 16));
	return (--i);
}

static int 	octal_sequence(const char *str, int i)
{
	char 	stack[4];
	int 	k;

	i++;
	k = 0;
	while (str[i] >= '0' && str[i] <= '7' && k < 3)
	{
		stack[k] = str[i];
		k++;
		i++;
	}
	stack[k] = '\0';
	ft_putchar(ft_atoi_base(stack, 8));
	return (--i);
}

static int 	simple_sequence(char c)
{
	if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'e' || c == 'E')
		ft_putchar('\x1B');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\\')
		ft_putchar('\\');
	else
		return (0);
	return (1);
}

int			handle_sequence(const char *str, int i)
{
	if (!str[i])
		return (i);
	else if (simple_sequence(str[i]))
		return (i);
	else if (str[i] == 'c')
		return (-1);
	else if (str[i] == '0')
		return (octal_sequence(str, i));
	else if (str[i] == 'x')
		return (hex_sequence(str, i));
	else
	{
		ft_putchar(str[i]);
		return (i);
	}
}
