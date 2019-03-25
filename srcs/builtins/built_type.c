/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:13:22 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 14:13:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "execute.h"
#include "builtins.h"

void			type_print_arr(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar(' ');
		i++;
	}
	if (i > 0)
		ft_putchar('\n');
}

static int		type_parse_flags(char **av, int *flags)
{
	int		i;

	i = 1;
	ft_memset(flags, '\0', sizeof(int) * 5);
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-a"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-f"))
			flags[1] = 1;
		else if (!ft_strcmp(av[i], "-p"))
			flags[2] = 1;
		else if (!ft_strcmp(av[i], "-t"))
			flags[3] = 1;
		else if (!ft_strcmp(av[i], "-P"))
			flags[4] = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

static int		type_iterate_args(char **av, int i, int *flags)
{
	int		flag;

	flag = SHERR_OK;
	while (av[i])
	{
		if ((type_find_alias(av[i], flags)
			|| type_find_function(av[i], flags)
			|| type_find_builtin(av[i], flags)
			|| type_find_keyword(av[i], flags)
			|| type_find_bin(av[i], flags)) && flag == SHERR_OK)
			flag = SHERR_OK;
		else
			flag = SHERR_ERR;
		i++;
	}
	return (flag);
}

/*
** type [-afptP] [name …]
*/

int				built_type(char **av, char **env)
{
	int		flags[5];
	int		i;

	env = NULL;
	i = type_parse_flags(av, flags);
	return (type_iterate_args(av, i, flags));
}
