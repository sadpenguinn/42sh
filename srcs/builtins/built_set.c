/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:31:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 13:31:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "readline.h"
#include "builtins.h"

static int		built_set_parse(char **av)
{
	if (!ft_strcmp(av[1], "-o"))
	{
		if (!ft_strcmp(av[2], "vi"))
			return (built_set_gvar(&g_mode, VI));
		else if (!ft_strcmp(av[2], "emacs"))
			return (built_set_gvar(&g_mode, READLINE));
		else if (!ft_strcmp(av[2], "echoe"))
			return (built_set_toggle(&g_echoe, TRUE, FALSE));
		else if (!ft_strcmp(av[2], "syntax"))
			return (built_set_toggle(&g_syntax, SYNTAX_ON, SYNTAX_OFF));
		else
		{
			built_set_print();
			return (SHERR_OK);
		}
	}
	if (!ft_strcmp(av[1], "-n"))
		return (built_set_gvar(&g_dontexec, TRUE));
	else
		return (built_set_usage());
}

/*
** Standard builtin 'set' with flags '-n' and '-o'
** for modifying shell behavior
*/

int				built_set(char **av, char **env)
{
	if (av[1])
		return (built_set_parse(av));
	else
		print_str_arr(env);
	return (SHERR_OK);
}
