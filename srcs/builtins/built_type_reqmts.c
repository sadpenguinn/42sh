/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_type_reqmts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:12:00 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 16:12:02 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "execute.h"
#include "builtins.h"

extern char		*g_built_in_lists[];

int				type_find_function(char *arg, int *flags)
{
	t_func	*function;
	size_t	len;
	size_t	i;

	i = 0;
	len = vector_get_len(g_func);
	while (i < len)
	{
		function = (t_func *)vector_get_elem(g_func, i);
		if (!ft_strcmp(function->name, arg))
		{
			ft_putstr(arg);
			if (flags[3])
				ft_putendl(" function");
			else
				ft_putendl(" is a shell function");
			return (1);
		}
		i++;
	}
	return (0);
}

int				type_find_alias(char *arg, int *flags)
{
	t_aliastb	*alias;

	if (!(alias = alias_find(arg, g_aliases)))
		return (0);
	ft_putstr(arg);
	if (flags[3])
		ft_putendl(" alias");
	else
	{
		ft_putstr(" is an alias for ");
		type_print_arr(alias->value);
	}
	return (1);
}

int				type_find_builtin(char *arg, int *flags)
{
	int		i;

	i = 0;
	while (g_built_in_lists[i])
	{
		if (!ft_strcmp(g_built_in_lists[i], arg))
		{
			ft_putstr(arg);
			if (flags[3])
				ft_putendl(" builtin");
			else
				ft_putendl(" is a builtin");
			return (1);
		}
		i++;
	}
	return (0);
}

int				type_find_keyword(char *arg, int *flags)
{
	if (!ft_strcmp(arg, "!") || !ft_strcmp(arg, "{")
		|| !ft_strcmp(arg, "}") || !ft_strcmp(arg, "case")
		|| !ft_strcmp(arg, "do") || !ft_strcmp(arg, "done")
		|| !ft_strcmp(arg, "elif") || !ft_strcmp(arg, "else")
		|| !ft_strcmp(arg, "esac") || !ft_strcmp(arg, "fi")
		|| !ft_strcmp(arg, "for") || !ft_strcmp(arg, "if")
		|| !ft_strcmp(arg, "in") || !ft_strcmp(arg, "then")
		|| !ft_strcmp(arg, "function") || !ft_strcmp(arg, "]]")
		|| !ft_strcmp(arg, "select") || !ft_strcmp(arg, "[["))
	{
		ft_putstr(arg);
		if (flags[3])
			ft_putendl(" keyword");
		else
			ft_putendl(" is a keyword");
		return (1);
	}
	return (0);
}

int				type_find_bin(char *arg, int *flags)
{
	t_hshtb	*bin;

	if (!(bin = hash_find(arg, g_path)))
		return (0);
	ft_putstr(arg);
	if (flags[3])
		ft_putendl(" file");
	else
	{
		ft_putstr(" is ");
		ft_putstr(bin->value);
		ft_putchar('\n');
	}
	return (1);
}
