/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 17:56:25 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell.h"

static int 			built_echo_usage(char c)
{
	char arg[3];

	arg[0] = '-';
	arg[1] = c;
	arg[2] = '\0';
	sputcmderr(sstrerr(SHERR_INVSNTX), "echo", arg);
	return (-1);
}

static void			print_string(const char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\\')
			ft_putchar(str[i]);
		else
			if ((i = handle_sequence(str, i + 1)) == -1)
				return ;
		i++;
	}
}

static void			print_strings(char **av, const int *flags, size_t i)
{
	size_t	size;

	size = size_str_arr(av + i);
	if (flags[0])
		size++;
	while (av[i])
	{
		if (flags[1])
			print_string(av[i]);
		else
			ft_putstr(av[i]);
		if (i < size)
			ft_putchar(' ');
		i++;
	}
	if (!flags[0])
		ft_putchar('\n');
}

static int		parse_flags(char **av, int *flags)
{
	int		i;
	int 	k;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			k = 1;
			while (av[i][k])
			{
				if (av[i][k] == 'n')
					flags[0] = 1;
				else if (av[i][k] == 'e')
					flags[1] = 1;
				else if (av[i][k] == 'E')
					flags[1] = 0;
				else
					return (built_echo_usage(av[i][k]));
				k++;
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

/*
** Builtin 'echo' parses flags and print strings.
** The following flags are supported: -n, -e, -E.
** -n -- print string without '\n' at the end.
** -e -- interpret sequences.
** -E -- don't interpret sequences.
*/

int					built_echo(char **av, char **env)
{
	int		flags[2];
	int 	i;

	env = NULL;
	flags[0] = 0;
	flags[1] = g_echoe == TRUE ? 1 : 0;
	if ((i = parse_flags(av, flags)) == -1)
		return (SHERR_ERR);
	print_strings(av, flags, (size_t)i);
	return (SHERR_OK);
}
