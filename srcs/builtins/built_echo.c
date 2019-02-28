/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 15:25:56 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void		print_strings(char **av, int *flags, size_t i)
{
	size_t	size;

	size = size_str_arr(av + i);
	while (av[i])
	{
		ft_putstr(av[i]);
		if (i < size)
			ft_putchar(' ');
		i++;
	}
	if (!flags[0])
		ft_putchar('\n');
}

static size_t		parse_flags(char **av, int *flags)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-n"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-e"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-E"))
			flags[0] = 0;
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

int				built_echo(char **av, char **env)
{
	int		flags[2];
	size_t	i;

	env = NULL;
	flags[0] = 0;
	flags[1] = 0;
	i = parse_flags(av, flags);
	print_strings(av, flags, i);
	return (SHERR_OK);
}
