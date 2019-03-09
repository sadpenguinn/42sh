/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_set_reqmts.c                                 :+:      :+:    :+:   */
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

int		built_set_usage(void)
{
	ft_putendl("Huita");
	return (SHERR_ERR);
}

int		built_set_toggle(int *var, int fval, int sval)
{
	if (*var == fval)
		*var = sval;
	else
		*var = fval;
	return (SHERR_OK);
}

int		built_set_gvar(int *var, int val)
{
	*var = val;
	return (SHERR_OK);
}

void	built_set_print(void)
{
	ft_putstr("vi:\t\t");
	ft_putendl(g_mode == VI ? "on" : "off");
	ft_putstr("emacs:\t\t");
	ft_putendl(g_mode == READLINE ? "on" : "off");
	ft_putstr("echoe:\t\t");
	ft_putendl(g_echoe == TRUE ? "on" : "off");
	ft_putstr("syntax:\t\t");
	ft_putendl(g_syntax == SYNTAX_ON ? "on" : "off");
}
