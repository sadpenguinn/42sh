/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:30:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/01 16:58:46 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		print_version(void)
{
	ft_putstr(SHELL_VERSION);
	ft_putstr(SHELL_AUTHORS);
	return (1);
}

static int		print_help(void)
{
	print_version();
	ft_putstr(SHELL_USAGE);
	ft_putstr(SHELL_OPT);
	ft_putstr(SHELL_OPT_C);
	ft_putstr(SHELL_OPT_H);
	ft_putstr(SHELL_OPT_V);
	ft_putstr(SHELL_LOPT);
	ft_putstr(SHELL_LOPT_H);
	ft_putstr(SHELL_LOPT_V);
	return (1);
}

static int		parse_files(int ac, char **av)
{
	ac = 0;
	av = NULL;
	return (1);
}

int				argv_parser(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (!ft_strcmp(av[1], "--version") || !ft_strcmp(av[1], "-v"))
		return (print_version());
	else if (!ft_strcmp(av[1], "--help") || !ft_strcmp(av[1], "-h"))
		return (print_help());
	else if (!ft_strcmp(av[1], "-c"))
		return (parse_input(ac, av));
	else
		return (parse_files(ac, av));
}
