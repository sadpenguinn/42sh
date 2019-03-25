/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset_reqmts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:04:26 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 16:04:27 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "shell.h"
#include "execute.h"

int		unset_print_error(char *arg)
{
	sputcmderr(sstrerr(SHERR_INVSNTX), "unset", arg);
	return (0);
}

int		unset_destroy_all(void)
{
	destroy_env();
	init_env(NULL, NULL);
	destroy_functions();
	destroy_function_args();
	init_functions();
	init_function_args();
	return (SHERR_OK);
}

int		unset_parse_flags(char **av, int *flags)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-f"))
			flags[0] = 1;
		else if (!ft_strcmp(av[i], "-n"))
			flags[1] = 1;
		else if (!ft_strcmp(av[i], "-v"))
			flags[2] = 1;
		else if (av[i][0] == '-')
			return (unset_print_error(av[i]));
		else
			return (1);
		i++;
	}
	return (1);
}

char	**unset_for(char **av)
{
	int		i;

	i = 1;
	while (av[i] && av[i][0] == '-')
		i++;
	return (av + i);
}

void	unset_delete_function(char *func)
{
	t_func	*function;
	size_t	len;
	size_t	i;

	i = 0;
	len = vector_get_len(g_func);
	while (i < len)
	{
		function = (t_func *)vector_get_elem(g_func, i);
		if (!ft_strcmp(function->name, func))
			vector_del_elem(&g_func, i);
		i++;
	}
}
