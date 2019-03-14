/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_flags_switcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:42:11 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:53:17 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		cond_switcher_for_one_other(char *flag, char *arg)
{
	if (!(ft_strcmp(flag, "-u")))
		return (u_conditions(arg));
	if (!(ft_strcmp(flag, "-w")))
		return (w_conditions(arg));
	if (!(ft_strcmp(flag, "-x")))
		return (x_conditions(arg));
	if (!(ft_strcmp(flag, "-z")))
		return (z_conditions(arg));
	return (conditions_print_error_syntax_message(flag));
}

int		cond_switcher_for_one(char *flag, char *arg)
{
	if (!flag || !arg)
		return (conditions_print_error_syntax());
	if (!(ft_strcmp(flag, "-b")))
		return (b_conditions(arg));
	if (!(ft_strcmp(flag, "-c")))
		return (c_conditions(arg));
	if (!(ft_strcmp(flag, "-e")))
		return (e_conditions(arg));
	if (!(ft_strcmp(flag, "-f")))
		return (f_conditions(arg));
	if (!(ft_strcmp(flag, "-g")))
		return (g_conditions(arg));
	if (!(ft_strcmp(flag, "-L")))
		return (bl_conditions(arg));
	if (!(ft_strcmp(flag, "-p")))
		return (p_conditions(arg));
	if (!(ft_strcmp(flag, "-r")))
		return (r_conditions(arg));
	if (!(ft_strcmp(flag, "-S")))
		return (bs_conditions(arg));
	if (!(ft_strcmp(flag, "-s")))
		return (s_conditions(arg));
	return (cond_switcher_for_one_other(flag, arg));
}

int		cond_switcher_for_two(char *flag, char *arg1, char *arg2)
{
	if (!flag || !arg1 || !arg2)
		return (conditions_print_error_syntax());
	if (!(ft_strcmp(flag, "=")))
		return (equal_str_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "!=")))
		return (not_equal_str_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-eq")))
		return (eq_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-ne")))
		return (ne_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-ge")))
		return (ge_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-lt")))
		return (lt_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-le")))
		return (le_conditions(arg1, arg2));
	return (conditions_print_error_syntax_message(flag));
}
