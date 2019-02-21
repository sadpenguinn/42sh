/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:30:20 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 20:50:18 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		print_version(void)
{
	ft_putendl(SHELL_VERSION);
	ft_putendl(SHELL_AUTHORS);
	return (1);
}

static int		print_help(void)
{
	print_version();
	ft_putendl(SHELL_USAGE);
	ft_putendl(SHELL_OPTIONS);
	return (1);
}

int 			parse_input(int ac, char **av)
{
	char 	*input;
	int 	i;

	i = 2;
	input = ft_strnew(0);
	while (i < ac)
	{
		input = ft_strjoin(input, " ", 1);
		input = ft_strjoin(input, av[i], 1);
		i++;
	}
	ft_putendl(input);
	ft_strdel(&input);
	return (1);
}

int 			parse_files(int ac, char **av)
{
	ac = 0;
	av = NULL;
	return (1);
}

int 			argv_parser(int ac, char **av)
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
